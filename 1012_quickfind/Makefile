SRCS := $(shell find . -maxdepth 1 -type f -name '*.c' -exec basename {} \;)
OBJS := $(SRCS:%.c=%.o)
DEPS := $(OBJS:%.o=%.d)
FLGS := -g -O0 -std=c2x -Wall -Werror -Wextra -pedantic -MMD -MP
CC   := gcc
EXE  := qfind

.PHONY: all bin clean

all: bin

bin: $(OBJS)
	$(CC) $(FLGS) -o $(EXE) $(OBJS)

%.o: %.c
# this target deletes the implicit rule for generating .o
# files--we only want to use the target from the next line

$(OBJS): %.o: %.c
# compile any .c file into the corresponding .o file
	$(CC) $(FLGS) -c $< -o $@

-include $(DEPS)

clean:
	-rm -f *.o *.d $(EXE)
