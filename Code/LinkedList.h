#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#define TEMP template <class T>


#include <iostream>
#include <exception>

#include "Compare.h"
using namespace std;

// Because we're working with templates and templates are 
// translated before compile time, we implement their code here 
// in the header file  


TEMP
class LinkedListNode{
    public:
        LinkedListNode(T data_in){
            data = data_in;
        }

        //Functions
        T getData(){
            return data;
        }
        LinkedListNode<T>* getNext(){
            return next;
        }

    private:
        T data;
        LinkedListNode<T>* next;

        template <class U> friend class LinkedList;
};



TEMP
class LinkedList{
    public:
        //Constructors
        LinkedList();
        LinkedList(T);
        LinkedList(LinkedListNode<T>*);


        //Functions
        bool append(T);
        bool remove(T);

        LinkedListNode<T>* find(T);
        LinkedListNode<T>* getHead(){
            return head;
        }

        int index(T);
        int getSize(){
            return size;
        }

    private:

        LinkedListNode<T>* head;
        int size;
};

TEMP
LinkedList<T>::LinkedList(){
    head = NULL;
    size = 0;
}

TEMP
LinkedList<T>::LinkedList(T data_in){
    head = new LinkedListNode<T>(data_in);
    size = 0;
}

TEMP
LinkedList<T>::LinkedList(LinkedListNode<T>* node){
    size = 1;
    head = node;
}

// adds data to the end of the list
TEMP
bool LinkedList<T>::append(T data_in){
    LinkedListNode<T>* curr;

    if (head == NULL){
        head = new LinkedListNode<T>(data_in);
        size ++;
        return true;
    }

    curr = head;

    while (curr->next != NULL){
        curr = curr->next;
    }

    curr->next = new LinkedListNode<T>(data_in);

    size ++;
    return true;
}

// Searches for node holding specified data in the list and returns it
// Reurns null if not found
TEMP 
LinkedListNode<T>* LinkedList<T>::find(T data){
    LinkedListNode<T>* curr = head;
    //Compare<T> comp;

    while (curr != NULL){
        if (Compare<T>::compare(curr->data,data) == 0){
            return curr;
        } 
        else {
            curr = curr->next;
        }                 
    }

    return curr;
}

// returns the index of the node holding the specified data
// returns -1 if it isn't found
TEMP 
int LinkedList<T>::index(T data){
    int index = 0;
    LinkedListNode<T>* curr = head;
    //Compare<T> comp;
    while (curr != NULL){
        if (Compare<T>::compare(curr->data,data) == 0){
            return index;
        }
        else{
            index ++;
            curr = curr->next;
        }
    }


    return -1;
}

// removes the node holding the specified data from the list
// returns false if the node isn't found
TEMP
bool LinkedList<T>::remove(T data_in){
    LinkedListNode<T>* curr = head,*prev = head;
    //Compare<T> comp;

    while (curr != NULL){
        if (Compare<T>::compare(data_in, curr->data) == 0){
            size --;

            if (curr->next != NULL){
                prev->next = curr->next;
            }
            else { //curr is the last node of the list
                curr = NULL;
            }

            return true;
        }
        else {
            prev = curr;
            curr = curr->next;
        }
    }

    return false;
}

#endif 