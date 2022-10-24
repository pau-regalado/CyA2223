SRC=../src/
INCLUDE=../include/
FLAGS=-std=c++14 -g -Wall

all: main 
all: string alphabet lenguage calculator main

string: 
	g++ $(FLAGS) $(SRC)string.cc -c

alphabet: 
	g++ $(FLAGS) $(SRC)alphabet.cc -c

calculator: 
	g++ $(FLAGS) $(SRC)calculator.cc -c

lenguage: 
	g++ $(FLAGS) $(SRC)language.cc -c

main:
	g++ $(FLAGS) $(SRC)main.cc string.o alphabet.o calculator.o language.o -o main

clean:
	rm main
	make
	./main ../dataFile/lenguajes.txt