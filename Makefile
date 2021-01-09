CC=gcc
CXX=g++
RM=rm -f
CPPFLAGS=-g $(shell root-config --cflags)
LDFLAGS=-g $(shell root-config --ldflags)

SRCS=tool.cc support.cc
OBJS=$(subst .cc,.o,$(SRCS))

all: tictactoe

tictactoe: tictactoe.o
	$(CXX) $(LDFLAGS) -o tictactoe $<

tictactoe.h: tictactoe.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
    $(RM) tictactoe.exe tictactoe tictactoe.o
