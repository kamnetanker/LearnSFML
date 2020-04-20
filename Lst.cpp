#ifndef _LST_
#include "Lst.h"
#endif
#ifndef _NODE_
#include "Nodes.h"
#endif
template <typename T>
List<T>::List() {
	this->head = nullptr;
	this->current = nullptr;
	this->tail = nullptr; 
}
template <typename T>
void List<T>::PopCurrent() {
	if(this->current->_next!=nullptr&&this->current->_prev!=nullptr){
	Node<T>* a = this->current;
	this->current = this->current->_next;
	a->_next->_prev = a->_prev;
	a->_prev->_next = a->_next;
	if (this->current->_prev == this->head) {
		this->head = a->_next;
		this->tail = a->_prev;
	}
	else if (this->current->_prev == this->tail) {
		this->tail = a->_prev;
		this->head = a->_next;
	}
	delete a;
	while (this->current->_index != 0) {
		this->current->_index--;
		this->current = this->current->_next;
	}
	}
	else {
		delete this->current;
		this->head = nullptr; 
	}
}
template <typename T>
bool List<T>::AddNode(T* node) {
	try{
		if (node != nullptr) {
			 
			if (this->head == nullptr) {
				this->head = new Node<T>();
				this->head->_value = node;
				this->current = this->head;
				this->tail = this->head;
				this->head->_index = 0;
			}
			else {
				Node<T>* temp = new Node<T>();
				this->tail->_next = temp; 
				this->tail->_next->_prev = this->tail;
				this->tail->_next->_index = this->tail->_index + 1;
				this->tail = this->tail->_next;
				this->tail->_next = this->head;
				this->head->_prev = this->tail;
				this->tail->_value = node;
				temp = nullptr; 
				delete temp;
			} 
			return true;
		}
		else {
			throw L"Nullptr exception.";
		}
	}
	catch (const wchar_t* a) {
		wprintf(a);
		return false;
	}
}
template <typename T>
bool List<T>::DeleteNode(int index) {
	try {
		if (index >= 0 && index <= this->tail->_index) {
			if (this->current->_index > index) {
				while (this->current->_index > index) {
					this->current = this->current->_prev;
				}
			}
			else if (this->current->_index < index) {
				while (this->current->_index < index) {
					this->current = this->current->_next;
				}
			}
			this->PopCurrent();
		}
		else {
			throw L"Index is out of range.";
		}
	}
	catch (const wchar_t* a) {
		wprintf(a);
		return false;
	}
	return true;
}
template <typename T>
T* List<T>::GetNode(int index) {
	T* ret=nullptr;
	try {
		if (index >= 0 && index <= this->tail->_index) {
			if (this->current->_index > index) {
				while (this->current->_index > index) {
					this->current = this->current->_prev;
				}
			}
			else if (this->current->_index < index) {
				while (this->current->_index < index) {
					this->current = this->current->_next;
				}
			}
			ret = this->current->_value;
		}
		else {
			throw L"Index is out of range.";
		}
	}
	catch (const wchar_t* a) {
		wprintf(a);
		return nullptr;
	}
	return ret;
}
template <typename T>
T* List<T>::PopNode(bool Fifo) {
	T* ret = nullptr;
	if (Fifo == true) {
		this->current = this->head;
		ret = this->current->_value;
		PopCurrent();
	}
	else {
		this->current = this->tail;
		ret = this->current->_value;
		PopCurrent();
	}
	return ret;
}
template <typename T>
T* List<T>::GetHead() {
	return this->head->_value;
}
template <typename T>
T* List<T>::GetTail() {
	return this->tail->_value;
}
template <typename T>
bool List<T>::PushNode(T* node) {
	try {
		if (node != nullptr) {
			return AddNode(node); 
		}
		else {
			throw L"Nullptr exception.";
		}
	}
	catch (const wchar_t* a) {
		wprintf(a);
		return false;
	}
}
template <typename T> 
bool List<T>::SetNode(int index, T* node) {
	T* ret = nullptr;
	try {
		if (node != nullptr) {
			ret = GetNode(index);
			*ret = *node;
			delete node;
		}
		else {
			throw L"Nullptr exception.";
		}
	}
	catch (const wchar_t* a) {
		wprintf(a);
		return false;
	}
	return true;
}

template <typename T>
List<T>::~List() { 
	if (this->head != nullptr) {
		this->current = this->head;
		this->current->_prev->_next = nullptr;
		while (this->current->_next != nullptr) {
			this->current = this->current->_next;
			delete this->current->_prev; 
		}
		delete this->current; 
	} 
}