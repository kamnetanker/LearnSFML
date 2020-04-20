#pragma once
#ifndef _LST_
#define _LST_
#endif // !_MMG_

#ifndef _NODE_
#include "Nodes.h"
#endif

#ifndef NULL
#define NULL 0
#endif // !NULL
#ifndef OPTIMAL
#define OPTIMAL true
#endif
#ifndef NO_OPTIMAL
#define NO_OPTIMAL false
#endif
#include "headers.h" 

template <typename T>
class List {
public: 
	List();
	bool AddNode(T* node); 
	bool DeleteNode(int index);
	T* GetNode(int index);
	T* PopNode(bool Fifo);
	T* GetHead();
	T* GetTail();
	bool PushNode(T* node); 
	bool SetNode(int index, T* node);
	~List();
private:
	Node<T>* head;
	Node<T>* current;
	Node<T>* tail;   
	void PopCurrent();
protected:

};
