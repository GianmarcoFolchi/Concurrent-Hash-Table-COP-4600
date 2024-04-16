CC=gcc
CFLAGS=-Wall -g -pthread
DEPS = hashdb.h rwlocks.h common.h common_threads.h
OBJ = chash.o hashdb.o rwlocks.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

chash: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o chash

.PHONY: clean