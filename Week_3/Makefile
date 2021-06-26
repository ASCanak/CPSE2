#############################################################################
#
# Project Makefile
#
# (c) Wouter van Ooijen (www.voti.nl) 2016
#
# This file is in the public domain.
# 
#############################################################################

# source files in this project (main.cpp is automatically assumed)
SOURCES := circle.cpp line.cpp picture.cpp rectangle.cpp

# header files in this project
HEADERS := circle.hpp drawable.hpp exceptions.hpp factory.hpp line.hpp picture.hpp rectangle.hpp

# other places to look for files for this project
SEARCH  := sources headers

# set REATIVE to the next higher directory 
# and defer to the Makefile.due there
RELATIVE := $(RELATIVE)../
include $(RELATIVE)Makefile.native