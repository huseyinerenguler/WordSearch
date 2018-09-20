#ifndef _NODE_
#define _NODE_

template <class T> class Node {
public:
	T data;
	Node *nextWord;
	Node *nextFile;
	
	Node (T data) {
		this->data = data;
		this->nextWord = NULL;
		this->nextFile = NULL;
	}
};

#endif
