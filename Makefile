CC = gcc
CFLAGS = -std=c11 -O2 -Wall -Iinclude

SRCS = $(wildcard src/*.c)
BINS = shellSort selectionSort heapsort quickSort bubbleSort straightInsertionSort

.PHONY: all clean

all: $(BINS)

shellSort: src/shellSort.c include/sort_main.h
	$(CC) $(CFLAGS) src/shellSort.c -o shellSort

selectionSort: src/selectionSort.c include/sort_main.h
	$(CC) $(CFLAGS) src/selectionSort.c -o selectionSort

heapsort: src/heapsort.c include/sort_main.h
	$(CC) $(CFLAGS) src/heapsort.c -o heapsort

quickSort: src/quickSort.c include/sort_main.h
	$(CC) $(CFLAGS) src/quickSort.c -o quickSort

bubbleSort: src/bubbleSort.c include/sort_main.h
	$(CC) $(CFLAGS) src/bubbleSort.c -o bubbleSort

straightInsertionSort: src/straightInsertionSort.c include/sort_main.h
	$(CC) $(CFLAGS) src/straightInsertionSort.c -o straightInsertionSort

clean:
	rm -f $(BINS)
