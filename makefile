#
# This makefile is provided as an example.  It can be modified
# to work for assignment 3 by replacing the 'abc123' entries
# with your UTSA id.

# The 'run' command will only work if you
# have the appropriate text files in the same directory, and
# they have the same names
#


PROGRAMS = ll

CC = gcc
CFLAGS =

all: $(PROGRAMS)

tidy:
	rm -f ,* .,* *~ core a.out graphics.ps

clean:
	rm -f *.o *.a $(PROGRAMS)

run:
	./ll

# *****************************
# compilations
stack.o: stack.c header.h
	$(CC) $(CFLAGS) -c stack.c

main.o: main.c header.h
	$(CC) $(CFLAGS) -c main.c

# *****************************
# generate executable
ll: stack.o main.o
	$(CC) $(CFLAGS) -o ll stack.o main.o
