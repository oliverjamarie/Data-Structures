
output: Main.o Notebook.o Topic.o
	g++ Main.o Notebook.o Topic.o -o output

Main.o: Main.cpp Notebook.o LinkedList.h Compare.h BinarySearchTree.h
	g++ -c Main.cpp

Notebook.o: Notebook.cpp Notebook.h Topic.o
	g++ -c Notebook.cpp

Topic.o: Topic.cpp Topic.h
	g++ -c Topic.cpp



clean:
	rm *.o output
