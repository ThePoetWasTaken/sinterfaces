.SUFFIXES:
CC = gcc
SRC = ./src
LANG = c
MAIN_EXEC = main
BUILD = ./build
CFLAGS = -I./include -I$(BUILD)/libs/include -fPIC
SUBDIRS = $(shell find $(SRC) -type d)
FILES = $(wildcard $(addsuffix /*.$(LANG),$(SUBDIRS)))
OBJS = $(patsubst $(SRC)/%.$(LANG), $(BUILD)/objs/%.o, $(FILES))
ALL_OBJS = $(LIBS) $(OBJS)

all: $(MAIN_EXEC)

debug:
	make CFLAGS='$(CFLAGS) -Wall -Wextra -g'

release:
	make CFLAGS='$(CFLAGS) -O3'

lib: lib_target

lib_target: $(MAIN_EXEC).so

$(MAIN_EXEC): $(ALL_OBJS)
	$(CC) $(ALL_OBJS) -o $@

$(BUILD)/objs/%.o: $(SRC)/%.$(LANG)
	$(CC) $(CFLAGS) -c $< -o $@

$(MAIN_EXEC).so: $(ALL_OBJS)
	$(CC) $(CFLAGS) $(ALL_OBJS) -shared -o $@

clean:
	rm $(OBJS) $(MAIN_EXEC)

.PHONY: all clean lib release debug