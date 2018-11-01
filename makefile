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
linkedlist.o: linkedlist.c header.h
	$(CC) $(CFLAGS) -c linkedlist.c

project.o: project.c header.h
	$(CC) $(CFLAGS) -c project.c

# *****************************
# generate executable
ll: linkedlist.o project.o
	$(CC) $(CFLAGS) -o ll linkedlist.o project.o
