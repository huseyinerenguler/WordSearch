#ifndef _BINARYTREE_
#define _BINARYTREE_

#include "TreeNode.h"

using namespace std;

template <class T> class BinaryTree {
public:
	TreeNode<T> *root;

	BinaryTree () {
		this->root = NULL;
	}
	
	void insert(T file, T word) {
		
		TreeNode<T> *temp = root;
		
		// if tree is empty
		if (temp == NULL) {
			temp = new TreeNode<T>(word);
			temp->listOfFiles.insert(file, word);
			root = temp;
		}
		
		// if tree is not empty
		else {
			while(true) {
				
				// left
				if (word < temp->data) {
					if (temp->leftChild == NULL) {
						temp->leftChild = new TreeNode<T>(word);
						temp = temp->leftChild;
						temp->listOfFiles.insert(file, word);
						return;
					}
					else
						temp = temp->leftChild;
				}
				
				// right
				else if (word > temp->data) {
					if (temp->rightChild == NULL) {
						temp->rightChild = new TreeNode<T>(word);
						temp = temp->rightChild;
						temp->listOfFiles.insert(file, word);
						return;
					}
					else
						temp = temp->rightChild;
				}
				
				// matches
				else if (word == temp->data) {
					temp->listOfFiles.insert(file, word);
					return;
				}
			}
		}		
	}
	
	void printListOfFiles(T word) {
		
		TreeNode<T> *temp = root;
		
		while(temp != NULL) {
			
			if (word == temp->data) {
				temp->listOfFiles.showSingleWord(word);
				return;
			}
			
			else if (word < temp->data)
				temp = temp->leftChild;
			
			else if (word > temp->data)
				temp = temp->rightChild;
		}
		
		cout << "    --> Word couldn't find." << endl;
	}	
};

#endif
