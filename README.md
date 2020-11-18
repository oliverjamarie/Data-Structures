Notebook

Included data structures are generic.  In C++ this is implemented through templates which is part of the precompilation process.  This is why their implementation is in their header files instead of cpp files.

See Main.cpp to see implementation examples.

Data structures currently implemented
- Single Linked List
- Binary Search Tree

The data structures rely on Compare.h to compare variables.  If the variable type isn't primitive, you will need to implement a comparator function.
    

# Binary Search Tree
- BinarySearchTree<T>
	- Variables
		- **BSTNode<T>\* root** (private)
		- **int size **(private)
		
	- Constructors
		- **BinarySearchTree()**
		- **BinarySearchTree(vector<T> in)**
		
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
		
