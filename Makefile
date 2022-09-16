# Starter Makefile
# add .cpp and .h files as specified in each task. 

main: main.o reservoir.o reverseorder.o
	g++ -o main main.o reservoir.o reverseorder.o

main.o: main.cpp reservoir.h reverseorder.h
	g++ -c main.cpp

reservoir.o: reservoir.cpp reservoir.h
	g++ -c reservoir.cpp

reverseorder.o: reverseorder.cpp reverseorder.h
	g++ -c reverseorder.cpp

clean:
	rm -f main.o reservoir.o reverseorder.o

