SRC=../src/
INCLUDE=../include/
FLAGS=-std=c++14 -g -Wall
 
all: token processor main

token: 
	g++ $(FLAGS) $(SRC)token.cc -c

processor: 
	g++ $(FLAGS) $(SRC)processor.cc -c

main:
	g++ $(FLAGS) $(SRC)main.cc token.o processor.o -o main

clean:
	rm main
	make
	./main ../dataFile/entrada.cc ../dataFile/salida.txt