CFLAGS_COMMON = -Wall -std=c++1y
CC = g++
BOOST_ROOT := $(HOME)/boost_1_82_0
BOOST_INC := -I$(BOOST_ROOT)/include
PROGRAM = finta
OBJECTS = main.o MatchResult.o Team.o Console.o Person.o Player.o League.o
DEBUG_FLAG =

.PHONY: clean purge all debug

all: $(PROGRAM)

$(PROGRAM): $(OBJECTS)
	$(CC) $(CFLAGS_COMMON) $(BOOST_INC) $(DEBUG_FLAG) -o $@ $^

%.o: %.cpp
	$(CC) $(CFLAGS_COMMON) $(BOOST_INC) $(DEBUG_FLAG) -c -o $@ $<

clean:
	@rm -f *.o

purge:
	@rm -f $(PROGRAM) *.o

debug: DEBUG_FLAG = -g -DDEBUG
debug: all
