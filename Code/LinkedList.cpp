#include "LinkedList.h"
#include <iostream>
using namespace std;



SingleNode::SingleNode(void *ptr){
	data = ptr;
}

DoubleNode::DoubleNode(void *ptr){
	data = ptr;
}



//Mode 1 ==> Single Linked List
//Mode 2 ==> Double Linked List
LinkedList::LinkedList(int mode = 1, void* ptr=NULL){
	if (mode == 1){
		root = new SingleNode(ptr);
	}
	else if (mode == 2){
		root = new DoubleNode(ptr);
	}
	else {
		throw "Invalid Mode";
	}
}