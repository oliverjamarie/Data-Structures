#include <iostream>
#include "Notebook.h"
#include "Topic.h"
#include "LinkedList.h"
#include <exception>

using namespace std;




int main (){
    Notebook *note = new Notebook("Test Notebook");
    Topic *topic = new Topic(0,"French");
    LinkedList list (1,note);
	SingleNode* test_node = (SingleNode*)list.root;



	Notebook* test = (Notebook*) test_node->data;


    return 0;
}

