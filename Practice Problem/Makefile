all: bin/pizza.o
	g++ -std=c++11 bin/pizza.o -o bin/pizza
	
bin/pizza.o: src/pizza.cpp
	g++ -c src/pizza.cpp -o bin/pizza.o
	
run:
	./bin/pizza
	
clean:
	-rm -f bin/*
	-rm -f test/out/*

