#include "daisy_pod.h"
#include "daisy_seed.h"
#include "daisysp.h"
#include "daisysp-lgpl.h"
#include <math.h>

using namespace daisy;
using namespace daisysp;

DaisyPod hw;

static void AudioCallback(AudioHandle::InterleavingInputBuffer  in,
                   		  AudioHandle::InterleavingOutputBuffer out,
                   		  size_t                                size)
{
	hw.ProcessAllControls();
	for (size_t i = 0; i < size; i += 2)
	{
		out[i] 		= in[i];
		out[i + 1] 	= in[i + 1];
	}
}

int main(void)
{
	hw.Init();
	hw.SetAudioBlockSize(4); // number of samples handled per callback
	hw.SetAudioSampleRate(SaiHandle::Config::SampleRate::SAI_48KHZ);
	hw.StartAdc();
	hw.StartAudio(AudioCallback);
	while(1) {}
}
