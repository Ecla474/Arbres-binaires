all: main.out

main.out: main.o abr.o element.o perf.o
	g++ -g -W -Wall main.o abr.o element.o perf.o -o main.out

main.o: main.cpp abr.h element.h
	g++ -g -W -Wall -c main.cpp

abr.o: abr.h abr.cpp element.h
	g++ -g -W -Wall -c abr.cpp -o abr.o

element.o: element.h element.cpp
	g++ -g -W -Wall -c element.cpp

perf.o: perf.h perf.cpp
	g++ -g -W -Wall -c perf.cpp -o perf.o


clean:
	rm *.o

veryclean: clean
	rm *.out
