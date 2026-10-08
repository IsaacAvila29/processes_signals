CC = cc
SRCS  := $(wildcard */*.c)
PROGS := $(SRCS:.c=)

all: $(PROGS)

%: %.c
	$(CC) -o $@ $<

clean:
	rm -f $(PROGS) */core
