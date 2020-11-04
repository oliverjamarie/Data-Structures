
output: Main.o Notebook.o Topic.o LinkedList.o
	g++ Main.o Notebook.o Topic.o LinkedList.o -o output

Main.o: Main.cpp Notebook.o 
	g++ -c Main.cpp

Notebook.o: Notebook.cpp Notebook.h Topic.o
	g++ -c Notebook.cpp

Topic.o: Topic.cpp Topic.h
	g++ -c Topic.cpp

LinkedList.o: LinkedList.h LinkedList.cpp
	g++ -c LinkedList.cpp


clean:
	rm *.o output