PARAMS=-Wall
CC=g++

PROGRAM=finta
OBJECTS=main.o MatchResult.o

all: $(PROGRAM)

$(PROGRAM): $(OBJECTS)
	$(CC) -o $(PROGRAM) $(PARAMS) $(OBJECTS)

MatchResult.o: MatchResult.hpp MatchResult.cpp
	$(CC) -c $(PARAMS) -c MatchResult.cpp

clean:
	rm -f *.o *.gch $(nomePrograma)

purge: clean
	rm -f $(PROGRAM)