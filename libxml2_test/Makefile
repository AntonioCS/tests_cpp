CC=g++
CFLAGS=-std=c++14 -Wall -g
LDFLAGS=`xml2-config --cflags`
LDLIBS=`xml2-config --libs`

libxml: main.cpp
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ $(LDLIBS)