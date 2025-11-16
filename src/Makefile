CC = gcc                         # The compiler to use
CFLAGS = -std=c99 -Wall -Iinclude # Compiler flags: use C99, show all warnings, add 'include' dir for headers
SRC = src/bubbleSort.c           # Source file(s)
OBJ = $(SRC:.c=.o)               # Object file(s), e.g., src/bubbleSort.o
TARGET = executable              # Name of the final program

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f src/*.o $(TARGET)
