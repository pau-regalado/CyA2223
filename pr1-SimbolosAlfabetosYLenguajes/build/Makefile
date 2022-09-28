SRC=../src/
INCLUDE=../include/
FLAGS=-std=c++14 -g -Wall

all: string main processor

string:
	g++ $(FLAGS) $(SRC)string.cc -c

processor:
	g++ $(FLAGS) $(SRC)processor.cc -c

main:
	g++ $(FLAGS) $(SRC)main.cc string.o processor.o -o main

clean:
	rm main