#ifndef _TREENODE_
#define _TREENODE_

#include "LinkedList.h"

template <class T> class TreeNode {
public:
	T data;
	TreeNode *leftChild;
	TreeNode *rightChild;
	LinkedList<string> listOfFiles;

	TreeNode () {
		this->leftChild = NULL;
		this->rightChild = NULL;
	}
	
	TreeNode (T data) {
		this->leftChild = NULL;
		this->rightChild = NULL;
		this->data = data;
	}
};

#endif
