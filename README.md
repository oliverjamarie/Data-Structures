Notebook

Included data structures are generic.  In C++ this is implemented through templates which is part of the precompilation process.  This is why their implementation is in their header files instead of cpp files.

See Main.cpp to see implementation examples.

Data structures currently implemented
- Single Linked List
- Binary Search Tree

The data structures rely on Compare.h to compare variables.  If the variable type isn't primitive, you will need to implement a comparator function.
    

# Binary Search Tree
BinarySearchTree<T> is a friend class of BSTNode so it can access its private members

- BSTNode<T>
	- Variables
		- **T data** (private)
		- **BSTNode<T>\* left** (private)
		- **BSTNode<T>\* right** (private)
	
	- Constructors
		- **BSTNode<T>(T)** 

	- Functions 
		- **T getData** Returns the data held inside the node
		- **void displayNode()** Prints the data inside the node


- BinarySearchTree<T>
	- Variables
		- **BSTNode<T>\* root** (private)
		- **int size** (private)
		
	- Constructors
		- **BinarySearchTree<T>()**
		- **BinarySearchTree<T>(vector<T> in)**
		
	- Functions
		- **int getSize()**
			Returns the size of the tree
		- **bool insert(T data)**
			- Inserts data into the tree
			- Returns true or false depending on whether or not the insertion succeeded
		- **bool balance()**
			Balances tree to minimze tree height
		- **void remove(T data)**
			Removes specified value from tree 
		- **void display(int mode)**
			- Prints the tree
			- 3 modes 
				- Mode 0: print tree in increasing order
				- Mode 1: print tree in decreasing order
				- Mode 2: print tree in traversal order   
		- **void clear()**
			Empties tree
		- **BSTNode<T>* getRoot()**
			Returns the root			
		- **vector<T> getTreeInc()**
			Returns a vector of the tree in increasing order
		- **vector<T> getTreeDec()**
			Returns a vector of the tree in decreasing order
		- **vector<T> getTreeTrav()**
			Returns a vector of the tree in traversal order


		
# Linked List
LinkedList<T> is a friend class of LinkedListNode so it can access its private members

- LinkedListNode<T>
	- Variables
		- **T data**
		- **LinkedListNode<T>\* next**
	
	- Constructors
		- **LinkedListNode<T>(T)**
	
	- Functions
		- **T getData()** Returns the data held inside the node
		- **LinkedListNode<T>\* getNext** Returns the next node in the list  

- LinkedList<T>
	- Variables
		- **LinkedListNode<T>\* head**
		- **int size**

	- Constructors
		- **LinkedList<T>()**
        - **LinkedList<T>(T)**
        - **LinkedList<T>(LinkedListNode<T>*)**

	- Functions
		- **bool append(T)** Adds item to the end of the list
		- **bool remove(T)** 
			- Removes specified node from the list
			- Returns false if it isn't found
		- **LinkedListNode<T>\* find(T)** 
			- Searches for node holding specified data in the list and returns it
			- Returns NULL if not found
		- **LinkedListNode<T>\* getHead()** Returns head node of the list
		- **int index(T)** 
			- Returns the index of the node holding the specified data 
			- Returns -1 if not found
		- **int getSize()** Returns the size of the list

# Comparator
Used by the data structures to compare data
Has various implementations for the base data types

- Compare<T>
	- Functions
		- **static int compare(T t1,T t2)** Compares 2 pieces of data
			- if returns < 0 ==> t1 < t2
			- if returns 0 ==> t1 == t2
			- if returns > 0 ==> t1 > t2 
		- **bool equals(T,T)** Determines whether or not 2 pieces of data are equal
