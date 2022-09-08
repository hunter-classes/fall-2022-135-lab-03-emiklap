# Starter Makefile
# add .cpp and .h files as specified in each task. 

main: main.o reservoir.o
	g++ -o main main.o reservoir.o

main.o: main.cpp reservoir.h
	g++ -c main.cpp

reservoir.o: reservoir.cpp reservoir.h
	g++ -c reservoir.cpp
clean:
	rm -f main.o reservoir.o

