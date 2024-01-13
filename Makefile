#!/usr/bin/make

# Default is gcc running on *NIX
# Comment out if not using this setup
COMPILE := gcc
LINK := gcc 
ARCHIVE := ar
DELETE := rm

# Add any additional compiler options here.
CMP_OPT :=
CMP_OPT += -std=c99
CMP_OPT += -O2
CMP_OPT += -Wall

# MK_OBJ is the option for compiling without linking
MK_OBJ :=
MK_OBJ += $(if $(findstring gcc, $(COMPILE)),-c,)

# LNK_OPT contains the options for the linker
LNK_OPT :=

# LIBRARY is the filename for the library to be built
LIBRARY :=
LIBRARY += $(if $(findstring ar, $(ARCHIVE)),liblog.a,)

# ARC_CMD accounts for a + before each object filename
# in Open Watcom
ARC_CMD := $(if $(findstring wlib, $(ARCHIVE)),+,)

# Options for the archiving utility
ARC_OPT :=
ARC_OPT += $(if $(findstring ar, $(ARCHIVE)),-rsv,)

# The next section accounts for different file extensions
# for the object files.
LOG_OBJ :=
LOG_OBJ += $(if $(findstring gcc, $(COMPILE)),log.o,)

# Portion of link command to go before the object file when
# compiling the test program
LNK_CMD :=
LNK_CMD += $(if $(findstring gcc, $(LINK)),-o test,)

.PHONY: clean test all

all: $(LIBRARY)
	@echo "Build complete"

# ARCHIVING PHASE:

$(LIBRARY): $(LOG_OBJ)
	$(ARCHIVE) $(ARC_OPT) $(LIBRARY) $(ARC_CMD)$(LOG_OBJ) $(ARC_CMD)

# COMPILATION PHASE:

$(LOG_OBJ): ./src/log.c ./src/log.h
	$(COMPILE) $(CMP_OPT) $(MACRO) $(MK_OBJ) ./src/log.c

# POST-BUILD PHASE:

clean:
	$(DELETE) $(LOG_OBJ)
