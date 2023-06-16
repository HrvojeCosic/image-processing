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
INCFILES=$(patsubst %.c,%.d,$(CFILES))

all: $(BINARY)

$(BINARY): $(OFILES)
	$(CC) -o $@ $^ -L$(LIB_STB_PATH) -lm

%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $<

deps:
	git clone git@github.com:nothings/stb.git
	sudo mv stb/stb_image.h stb/stb_image_write.h /usr/local/include
	rm -rf stb

clean:
	rm -rf $(BINARY) $(OFILES) $(INCFILES)

-include $(INCFILES)

diff:
	@git status
	@git diff --statilters_internal.h"

