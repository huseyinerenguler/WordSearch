
#ifndef _LINKED_LIST
#define _LINKED_LIST
#include "Node.h"

using namespace std;

template <class T> class LinkedList {
public:	
	Node<T> *head;
	
	LinkedList () {
		this->head = NULL;
	}
	
	void insert(T file, T word) {
		
		Node<T> *temp = head;
		
		// if list is empty
		if (temp == NULL) {
			temp = new Node<T>(word);
			temp->nextFile = new Node<T>(file);
			temp->nextWord = NULL;
			head = temp;
		}
		
		// if list is not empty
		else {
			while(temp != NULL) {
				
				// word found, just change file part.
				if (temp->data == word) {
					while (temp->nextFile != NULL) {
						if (temp->data == file)
							return;	
						temp = temp->nextFile;
					}
					
					if (temp->data != file)
						temp->nextFile = new Node<T>(file);
					return;	
				}
				
				// word not found, add to end.
				else if (temp->data != word && temp->nextWord == NULL) {					
					temp->nextWord = new Node<T>(word);
					temp->nextWord->nextFile = new Node<T>(file);
					return;
				}
				
				temp = temp->nextWord;
			}			
		}
	}	
	
	void showAll() {
		
		Node<T> *temp = head;
		
		while (temp != NULL) {
			cout << temp->data << " --> ";
						
			Node<T> *temp2 = temp->nextFile;
			
			while (temp2 != NULL) {
				cout << temp2->data << " - ";
				temp2 = temp2->nextFile;
			}
			
			cout << endl;
			temp = temp->nextWord;
		}
	}
	
	void showSingleWord (T word) {
		
		Node<T> *temp = head;
		
		while (temp->data != word) {
			if (temp->nextWord == NULL){
				cout << "    --> Word couldn't find." << endl;
				return;
			}
				
			temp = temp->nextWord;
		}
		
		cout << "    " << "WORD: " << temp->data << "\n" << endl;
		
		temp = temp->nextFile;
		
		int count = 1;
		while (temp != NULL) {
			cout << "    " << count << "- " << temp->data << endl;
			temp = temp->nextFile;
			count++;
		}
	}	
};

#endif
