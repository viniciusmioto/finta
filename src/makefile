PARAMS=-Wall
CC=g++

PROGRAM=finta
OBJECTS=main.o MatchResult.o Team.o Console.o Person.o Player.o

.PHONY: clean purge all

all: $(PROGRAM)

$(PROGRAM): $(OBJECTS)
	$(CC) $(CFLAGS) -o  $@ $^

clean:
	@rm -f *.o

purge:   
	@rm -f $(PROGRAM) *.o