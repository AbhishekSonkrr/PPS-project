CC = gcc
CFLAGS = -std=c11 -O2 -Wall -Wextra -g
SRCS = main.c bubble.c heap.c quick.c selection.c shell.c insertion.c utils.c
OBJS = $(SRCS:.c=.o)
TARGET = sort_demo

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

%.o: %.c sorts.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
