#pragma once
#ifndef _NODE_
#define _NODE_
#endif // !_MMG_

#ifndef NULL
#define NULL 0
#endif // !NULL
template <typename T>
class Node {
public:
	T* _value;
	Node* _prev;
	Node* _next;
	int _index;
	~Node() {
		delete this->_value;
	}
};
template <typename T>
struct MultiNode {
	T* _value;
	int _nodeArraySize;
	MultiNode* _nodeArray;
};