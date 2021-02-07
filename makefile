CFLAGS=-g -ansi -pedantic -Wall -std=c++11 #-DMAP
analog: main.o FluxLog.o Stats.o toolmain.o toolmain1.o
	g++ -o analog $(CFLAGS) main.o FluxLog.o Stats.o toolmain.o toolmain1.o
main.o: main.cpp
	g++ -c $(CFLAGS) main.cpp
FluxLog.o: FluxLog.cpp
	g++ -c $(CFLAGS) FluxLog.cpp
Stats.o: Stats.cpp
	g++ -c $(CFLAGS) Stats.cpp
toolmain.o: toolmain.cpp
	g++ -c $(CFLAGS) toolmain.cpp
toolmain1.o: toolmain1.cpp
	g++ -c $(CFLAGS) toolmain1.cpp
clean:
	rm analog *.o
