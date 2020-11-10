#include <iostream>
#include "Notebook.h"
#include "Topic.h"
#include "LinkedList.h"
#include <exception>
#include "BinarySearchTree.h"
#include <ctime>

using namespace std;

void testLinkedList(){
LinkedList<int>* list = new LinkedList<int>();
    LinkedListNode<int>* curr , *node;
    int index;


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

    node = list->find(5);

    if (node == NULL){
        cout << "Node not found\n";
    }
    else{
        cout << "FOUND NODE\t" <<  node->getData()<<endl;
    }

    list->remove(5);

    node = list->find(5);

    if (node == NULL){
        cout << "Node not found, it was removed\n";
    }
    else{
        cout << "FOUND NODE\t" <<  node->getData()<<endl;
    }

}


void testBST(){
    BinarySearchTree<int>* bst = new BinarySearchTree<int>();
    srand((unsigned) time(0));
    int num ;
    for (int i = 0; i < 10; i ++){
        num = rand() % 100;
        cout << "ADDING\t" << num << endl;
        bst->insert(num);
    }
    
    bst->display(0);
    bst->display(1);
    bst->display(2);
}

int main (){
    Notebook note =  Notebook("Test Notebook");
    Notebook other =  Notebook("Test Notebook");
    Topic *topic = new Topic(0,"French");
    
    //testBST();

    testLinkedList();

    return 0;
}

// The following may be unnecessary but it is kept for potential reference

/* 
template class Node<int>;
template class LinkedList<int>; */