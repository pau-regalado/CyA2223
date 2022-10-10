SRC=../src/
INCLUDE=../include/
FLAGS=-std=c++14 -g -Wall

all: string alphabet lenguage processor main

string: 
	g++ $(FLAGS) $(SRC)string.cc -c

alphabet: 
	g++ $(FLAGS) $(SRC)alphabet.cc -c

processor: 
	g++ $(FLAGS) $(SRC)processor.cc -c

lenguage: 
	g++ $(FLAGS) $(SRC)language.cc -c

main:
	g++ $(FLAGS) $(SRC)main.cc string.o alphabet.o processor.o language.o -o main

clean:
	rm main
	make