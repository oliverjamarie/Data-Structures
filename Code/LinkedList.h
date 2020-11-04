#ifndef LINKED_LIST_H
#define LINKED_LIST_H

//Singular direction node (next)
class SingleNode {
    public:
		SingleNode(void* ptr);
		void* data;
		SingleNode* next;

};


//Double direction node (next and previous)
class DoubleNode{
	public:
		DoubleNode(void* ptr);
		
		void* data;
		DoubleNode* next;
		DoubleNode* prev;

};

class LinkedList{
    public:
        LinkedList (int mode, void* ptr);

        void* root;
};


#endif