#include <iostream>
#include "Notebook.h"
#include "Topic.h"
#include "LinkedList.h"
#include <exception>

using namespace std;




int main (){
    Notebook note =  Notebook("Test Notebook");
    Notebook other =  Notebook("Test Notebook");
    Topic *topic = new Topic(0,"French");
    LinkedList<int>* list = new LinkedList<int>();
    Node<int>* curr , *node;
    int index;

    cout << "Are they equal?\t" << list->equals(5,5) << endl;

    for (int i = 0; i < 10; i ++){
        list->append(i);
    }

    node = list->find(11);

    if (node == NULL){
        cout << "Node not found\n";
    }
    else{
        cout << "FOUND NODE\t" <<  node->getData()<<endl;
    }

    index = list->index(6);

    cout << "INDEX: \t"<<index<<endl;


    curr = list->getHead();

    cout << "Size "<< list->getSize() <<endl;

    while(curr != NULL){
        cout << curr->getData()<<endl;
        curr = curr->getNext();
    }



    return 0;
}

template class Node<int>;
template class LinkedList<int>;