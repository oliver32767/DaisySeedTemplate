# Project Name
TARGET = Template
USE_DAISYSP_LGPL = 1

# Sources
CPP_SOURCES = src/Main.cpp

# Library Locations
LIBDAISY_DIR = lib/libDaisy/
DAISYSP_DIR = lib/DaisySP/

# Core location, and generic Makefile.
SYSTEM_FILES_DIR = $(LIBDAISY_DIR)/core
include $(SYSTEM_FILES_DIR)/Makefile
