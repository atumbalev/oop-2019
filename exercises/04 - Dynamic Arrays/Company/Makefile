FLAGS=-std=c++14

output: main.o Worker.o Company.o
	g++ main.o Worker.o Company.o ${FLAGS} -o output

main.o: main.cpp Company.hpp Worker.hpp
	g++ ${FLAGS} -c main.cpp

Worker.o: Worker.hpp Worker.cpp
	g++ ${FLAGS} -c Worker.cpp

Company.o: Company.hpp Company.cpp Worker.hpp
	g++ ${FLAGS} -c Company.cpp

clean:
	rm *.o output
