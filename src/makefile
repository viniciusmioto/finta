PARAMS=-Wall
CC=g++

PROGRAM=finta
OBJECTS=main.o MatchResult.o Team.o Console.o

all: $(PROGRAM)

$(PROGRAM): $(OBJECTS) json.hpp
	$(CC) -o $(PROGRAM) json.hpp $(PARAMS) $(OBJECTS)

MatchResult.o: MatchResult.hpp MatchResult.cpp
	$(CC) -c $(PARAMS) -c MatchResult.cpp

clean:
	rm -f *.o *.gch $(nomePrograma)

purge: clean
	rm -f $(PROGRAM)