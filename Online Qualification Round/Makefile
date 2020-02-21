all: bin/lib.o bin/solver.o
	g++ bin/lib.o bin/solver.o -o bin/solver

bin/lib.o: src/lib.cpp include/lib.hpp
	g++ -c src/lib.cpp -o bin/lib.o

bin/solver.o: src/solver.cpp
	g++ -c src/solver.cpp -o bin/solver.o

run:
	./solver

clean:
	rm bin/*.o bin/solver
	rm test/output/*.out