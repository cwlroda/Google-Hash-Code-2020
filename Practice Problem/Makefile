all: bin/pizza.o bin/adder.o
	g++ -std=c++11 bin/pizza.o -o bin/pizza
	g++ -std=c++11 bin/adder.o -o bin/adder

bin/pizza.o: src/pizza.cpp
	g++ -c src/pizza.cpp -o bin/pizza.o

bin/adder.o: src/adder.cpp
	g++ -c src/adder.cpp -o bin/adder.o

run:
	./test.sh

clean:
	-rm -f bin/*
	-rm -f test/out/*

