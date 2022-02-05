CC := gcc
CFLAGS := -g -Wall
OBJ := main.o tree.o
DEPS := node.h tree.h

all: P0 clean

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

P0: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	
.PHONY: clean

clean:
	rm -rf *.o
