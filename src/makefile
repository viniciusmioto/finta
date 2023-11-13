CC = g++
CFLAGS_COMMON = -pedantic-errors -Wall -Wextra -Werror -std=c++20 -O3
BOOST_ROOT := -I$(HOME)/boost_1_82_0
PROGRAM = finta
OBJECTS = main.o \
		League.o \
		Match.o \
		MatchInfo.o \
		MatchResult.o \
		Team.o \
		Console.o \
		Person.o \
		Staff.o \
		Player.o \
		Fact.o \
		Goal.o \
		YellowCard.o \
		RedCard.o \
		MatchStats.o \

.PHONY: clean purge all debug

all: $(PROGRAM)

$(PROGRAM): $(OBJECTS)
	$(CC) $(CFLAGS_COMMON) $(BOOST_ROOT) $(DEBUG_FLAG) -o $@ $^

%.o: %.cpp
	$(CC) $(CFLAGS_COMMON) $(BOOST_ROOT) $(DEBUG_FLAG) -c -o $@ $<

clean:
	@rm -f $(PROGRAM) *.o

debug: DEBUG_FLAG = -g -DDEBUG
debug: all
