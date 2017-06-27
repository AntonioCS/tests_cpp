CC=g++
CFLAGS=-std=c++14 -Wall -Werror -g
LDFLAGS=
LDLIBS=`pkg-config --libs --cflags libcurl`

curl_test: main.cpp Kong/Request.cpp
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ $(LDLIBS)