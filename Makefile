CFLAGS=-Wall -g -std=c++14 -o
CC=g++

test1: test1.cpp
	$(CC) $(CFLAGS) $@ $^

sum_num: sum_num.cpp
	$(CC) $(CFLAGS) $@ $^
	
string_test: string_test.cpp
	$(CC) $(CFLAGS) $@ $^
	
vec_test: vec_test.cpp
	$(CC) $(CFLAGS) $@ $^
	
class: class.cpp
	$(CC) $(CFLAGS) $@ $^

numwords: numberToWords/*.cpp
	$(CC) $(CFLAGS) $@ $^
	
replace: replace.cpp
	$(CC) $(CFLAGS) $@ $^

	

