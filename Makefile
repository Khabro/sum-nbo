
all: sum-nbo

sum-nbo: main.o read_num.o
	g++ -o sum-nbo main.o read_num.o

main.o: read_num.h main.cpp
	g++ -c -o main.o main.cpp

read_num.o: read_num.h read_num.cpp
	g++ -c -o read_num.o read_num.cpp

clean:
	rm -f sum-nbo
	rm -f *.o
