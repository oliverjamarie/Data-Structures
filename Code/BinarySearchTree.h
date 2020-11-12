#ifndef BST_H
#define BST_H


#define TEMP template <class T>

#include <iostream>
#include <exception>
#include <string>
#include "Compare.h"

using namespace std;

// Because we're working with templates and templates are 
// translated before compile time, we implement their code here 
// in the header file  

TEMP
class BSTNode {
    private:
        T data;
        BSTNode<T>* left;
        BSTNode<T>* right;

    public:
        BSTNode(T data_in){
            data = data_in;
            left = NULL;
            right = NULL;
        }
        T getData(){
            return data;
        }
        void displayNode();

    template <class U> friend class BinarySearchTree;
};

TEMP
void BSTNode<T>::displayNode(){
    cout << data <<endl;
}

TEMP
class BinarySearchTree {
    private:
        bool insertIntoTree(T, BSTNode<T>*);
        bool removeFromTree(T, BSTNode<T>*, BSTNode<T>*);
        void displayTreeIncOrder(BSTNode<T>*);
        void displayTreeDecOrder(BSTNode<T>*);
        void displayTreeTraversOrder(BSTNode<T>*);
        BSTNode<T>* find(T, BSTNode<T>*);

        int size;
        BSTNode<T>* root;

    public:
        BinarySearchTree(){
            size = 0;
            root = NULL;
        }
        int getSize(){
            return size;
        }
        bool insert(T);
        bool balance();
        bool remove(T);
        BSTNode<T>* getRoot(){
            return root;
        }
        void display(int);
};

TEMP
bool BinarySearchTree<T>:: insert(T data_in){
    if (root == NULL){
        root = new BSTNode<T>(data_in);
        return true;
    }
    return insertIntoTree(data_in,root);
}

TEMP 
bool BinarySearchTree<T>::insertIntoTree(T data_in, BSTNode<T>* parent){

    if (Compare<T>::compare(data_in,parent->data) <= 0){
        if (parent->left == NULL){
            parent->left = new BSTNode<T>(data_in);
            return true;
        }
        return insertIntoTree(data_in, parent->left);
    }
    else {
        if (parent->right == NULL){
            parent->right = new BSTNode<T>(data_in);
            return true;
        }
        return insertIntoTree(data_in, parent->right);
    }
}


//NOT YET IMPLEMENTED
TEMP 
bool BinarySearchTree<T>::balance(){
    return true;
}

// mode 0   ==> display tree in increasing order
// mode 1   ==> display tree in decreasing order
// mode 2   ==> display tree in traversal order
TEMP
void BinarySearchTree<T>::display(int mode){
    if (root != NULL){
        if (mode == 0){
            displayTreeIncOrder(root);
        }
        else if (mode == 1){
            displayTreeDecOrder(root);
        }
        else if (mode == 2){
            displayTreeTraversOrder(root);
        }
        else
        {
            cout << "Invalid Mode\n";
        }

        cout << endl << endl;
        
    }
    else{
        cout << "EMPTY\n";
    }
    
}

TEMP
void BinarySearchTree<T>::displayTreeIncOrder(BSTNode<T>* node){
    if (node == NULL){
        return;
    }
    displayTreeIncOrder(node->left);
    node->displayNode();
    displayTreeIncOrder(node->right);
}

TEMP
void BinarySearchTree<T>::displayTreeDecOrder(BSTNode<T>* node){
    if (node == NULL){
        return;
    }
    displayTreeDecOrder(node->right);
    node->displayNode();
    displayTreeDecOrder(node->left);
}

TEMP
void BinarySearchTree<T>::displayTreeTraversOrder(BSTNode<T>* node){
    if (node == NULL){
        return;
    }
    node->displayNode();
    displayTreeDecOrder(node->left);
    displayTreeDecOrder(node->right);
    
}


TEMP
BSTNode<T>* BinarySearchTree<T>::find(T data_in, BSTNode<T>* node){
    //Compare<T> comp;

    if (node == NULL){
        return NULL;
    }

    if (Compare<T>::compare(data_in, node ->data) == 0){
        return node;
    }
    else if (Compare<T>::compare(data_in, node->data) < 0){
        return find(data_in, node->left);
    }
    else {
        return find(data_in, node->right);
    }
}

#endif