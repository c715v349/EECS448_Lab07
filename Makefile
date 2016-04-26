Lab02: main.o test.o
	g++ -g -std=c++11 -Wall main.o test.o -o Lab02
test.o: test.cpp test.h LinkedList.h LinkedList.hpp Node.hpp Node.h
	g++ -g -c -std=c++11 -Wall test.cpp
main.o: main.cpp LinkedList.h LinkedList.hpp Node.h test.h Node.hpp
	g++ -g -c -std=c++11 -Wall main.cpp

clean:
	rm *.o Lab02
	echo clean done
