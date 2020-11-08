#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#define TEMP template <class T>


#include <iostream>
#include <exception>
#include <type_traits>

using namespace std;


// Because we're working with templates and templates are 
// translated before compile time, we implement their code here 
// in the header file  


TEMP
class Node{
    public:
        Node(T data_in){
            data = data_in;
        }

        //Functions
        T getData(){
            return data;
        }
        Node<T>* getNext(){
            return next;
        }
        bool compare(T,T);
    private:
        T data;
        Node<T>* next;

        template <class U> friend class LinkedList;
};



TEMP
class LinkedList{
    public:
        //Constructors
        LinkedList();
        LinkedList(T);
        LinkedList(Node<T>*);


        //Functions
        bool append(T);
        bool equals(T,T);
        
        Node<T>* find(T);
        Node<T>* getHead(){
            return head;
        }
        int index(T);
        int getSize(){
            return size;
        }



    private:

        Node<T>* head;
        int size;
};

TEMP
LinkedList<T>::LinkedList(){
    head = NULL;
    size = 0;
}

TEMP
LinkedList<T>::LinkedList(T data_in){
    head = new Node<T>(data_in);
    size = 0;
}

TEMP
LinkedList<T>::LinkedList(Node<T>* node){
    size = 1;
    head = node;
}

TEMP
bool LinkedList<T>::append(T data_in){
    Node<T>* curr;

    if (head == NULL){
        head = new Node<T>(data_in);
        size ++;
        return true;
    }

    curr = head;

    while (curr->next != NULL){
        curr = curr->next;
    }

    curr->next = new Node<T>(data_in);

    size ++;
    return true;
}

TEMP 
Node<T>* LinkedList<T>::find(T data){
    Node<T>* curr = head;

    while (curr != NULL){
        if (equals(curr->data,data)){
            return curr;
        } 
        else {
            curr = curr->next;
        }                 
    }

    return curr;
}

TEMP 
int LinkedList<T>::index(T data){
    int index = 0;
    Node<T>* curr = head;

    while (curr != NULL){
        if (equals(curr->data, data)){
            return index;
        }
        else{
            index ++;
            curr = curr->next;
        }
    }


    return -1;
}


//Implementation of the various forms of LinkedList.equals()
TEMP
bool LinkedList<T>::equals(T obj1, T obj2){

    
    try {
        return obj1.equals(obj2);
    }
    catch (string exceptionStr){
        cout << exceptionStr << endl;
    }

   return false;
}

template<> 
bool LinkedList<int>::equals(int num1, int num2){
    return num1 == num2;
}

template<> 
bool LinkedList<float>::equals(float num1, float num2){
    return num1 == num2;
}

template<> 
bool LinkedList<double>::equals(double num1, double num2){
    return num1 == num2;
}

template<> 
bool LinkedList<char>::equals(char char1, char char2){
    return char1 == char2;
}

#endif