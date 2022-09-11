CC=gcc
CFLAGS= -Wall -Wextra --pedantic-errors -O3

example: example.o priority_queue.o
	$(CC) $(CFLAGS) $^ -o $@

example.o: example.c priority_queue.h
	$(CC) $(CFLAGS) -c -DT=int  $<

priority_queue.o: priority_queue.c priority_queue.h
	$(CC) $(CFLAGS) -c  $< -DT=int 