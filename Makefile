
# Variables to control Makefile operation

CC = g++
CFLAGS = -Wall -g

longest-palindrome: longest-palindrome.o
	$(CC) $(CFLAGS) -o longest-palindrome longest-palindrome.o

longest-palindrome.o: longest-palindrome.cpp
	$(CC) $(CFLAGS) -c longest-palindrome.cpp

clean:
	rm -rf longest-palindrome longest-palindrome.o
