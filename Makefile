# Library Dependencies
#
# This Makefile requires the following libraries:
# - stb: https://github.com/nothings/stb
#


BINARY=bin
CODEDIRS=. $(shell find src -type d)
INCDIRS=. ./include
LIB_STB_PATH = /usr/local/include/stb

CC=gcc
OPT=-O0
#Generate files including make rules for .h deps
DEPFLAGS=-MP -MD 
CFLAGS=-Wall -Wextra -g $(foreach DIR,$(INCDIRS),-I$(DIR)) $(OPT) $(DEPFLAGS)

CFILES=$(foreach DIR,$(CODEDIRS),$(wildcard $(DIR)/*.c))
OFILES=$(patsubst %.c,%.o,$(CFILES))
DEPFILES=$(patsubst %.c,%.d,$(CFILES))

all: $(BINARY)

$(BINARY): $(OFILES)
	$(CC) -o $@ $^ -L$(LIB_STB_PATH) -lm

%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(BINARY) $(OFILES) $(DEPFILES)

-include $(DEPFILES)

diff:
	@git status
	@git diff --statilters_internal.h"
