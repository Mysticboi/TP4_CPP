CFLAGS=-g -ansi -pedantic -Wall -std=c++11 #-DMAP
exe: main.o FluxLog.o Stats.o
	g++ -o exe $(CFLAGS) main.o FluxLog.o Stats.o
main.o: main.cpp
	g++ -c $(CFLAGS) main.cpp
FluxLog.o: FluxLog.cpp
	g++ -c $(CFLAGS) FluxLog.cpp
Stats.o: Stats.cpp
	g++ -c $(CFLAGS) Stats.cpp
clean:
	rm exe *.o
