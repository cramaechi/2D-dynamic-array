twod: main.o twod.o
	g++ main.o twod.o -o twod

main.o: main.cpp
	g++ -c main.cpp
	
twod.o: twod.cpp
	g++ -c twod.cpp

clean:
	rm *.o twod
