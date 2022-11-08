SRC=../src/
INCLUDE=../include/
FLAGS=-std=c++14 -g -Wall

all: fraction main

fraction:
	g++ $(FLAGS) $(SRC)fraction.cc -c

main:
	g++ $(FLAGS) $(SRC)main.cc fraction.o -o main

clean:
	rm main