CFLAGS=-Wall -g -std=c++1y
CC=g++

BOOST_ROOT := $(HOME)/boost_1_82_0
BOOST_INC := -I$(BOOST_ROOT)/include 

PROGRAM=finta
OBJECTS=main.o MatchResult.o Team.o Console.o Person.o Player.o

.PHONY: clean purge all

all: $(PROGRAM)

$(PROGRAM): $(OBJECTS)
	$(CC) $(CFLAGS) $(BOOST_INC) -o  $@ $^ 

%.o: %.cpp
	$(CC) $(CFLAGS) $(BOOST_INC) -c -o $@ $<

clean:
	@rm -f *.o

purge:
	@rm -f $(PROGRAM) *.o
