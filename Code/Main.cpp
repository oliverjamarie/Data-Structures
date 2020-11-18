#include <iostream>
#include "Notebook.h"
#include "Topic.h"
#include "LinkedList.h"
#include <exception> // not required for full release
#include "BinarySearchTree.h"
#include <ctime> // not required for full release, used to generate random numbers in testing
#include <vector>

using namespace std;

void testVector(vector<int> &in);

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

    // Root

    for (int i = 0; i < 10; i ++){
        num = rand() % 100;
        cout << "ADDING\t" << num << endl;
        bst->insert(num);
    }

    cout << "\n\nSIZE\t" << bst->getSize() <<endl;
    bst->display(2);

    bst->balance();
    bst->display(2);

    //delete bst;
}
void testVector(vector<int> &in){
    int size = in.size();

    for (int i = 0; i < size; i ++){
        cout << in[i] <<endl;
        //in[i] ++;
    }

}
int main (){
    Notebook note =  Notebook("Test Notebook");
    Notebook other =  Notebook("Test Notebook");
    Topic *topic = new Topic(0,"French");
    vector<int> set;
    
    /* for (int i = 0; i < 20; i ++){
        set.push_back(i);
    }

    testVector(set);

    for (int i : set){
        cout << i <<endl;
    } */

    

    testBST();


    //testLinkedList();

    return 0;
}

// The following may be unnecessary but it is kept for potential reference

/* 
template class Node<int>;
template class LinkedList<int>; */