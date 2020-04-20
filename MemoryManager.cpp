#include "MemoryManager.h"
template <typename T>
MemoryManager<T>::MemoryManager() {
	//LoggingPls
}
template <typename T>
T MemoryManager<T>::CreateInstance() {
	T* _instance = new T();
	return *_instance;
}
template <typename T>
T* MemoryManager<T>::CreatePointerInstance() {
	T* _instance = new T();
	return _instance;
}
template <typename T>
T* MemoryManager<T>::CreateArrayInstance(int length) {
	T* _instance = new T[length];
	return _instance;
}
template <typename T>
T** MemoryManager<T>::CreateTableInstance(int rows, int columns) {
	T** _instance = new T*[rows];
	for (int i = 0; i < rows; i++) _instance[i] = this->CreateArrayInstance(columns); 
	return _instance;
}
template <typename T>
T* MemoryManager<T>::ResizeArrayInstance(T* array, int oldLength, int newLength) {
	try{
	if(array!=nullptr){
	T* _instance = this->CreateArrayInstance(newLength);
	if (oldLength > newLength) { 
		oldLength = newLength; 
	}
	for (int i = 0; i < oldLength; i++) {
		_instance[i] = array[i];
	}
	delete[] array;
	return _instance;
	}
	else {
		throw L"Nullptr exception";
		return nullptr;
	}
	}
	catch (const wchar_t* a) {
		wprintf(a);
		return nullptr;
	}
}
template <typename T>
T** MemoryManager<T>::ResizeTableInstance(T** table, int oldRows, int oldColumns, int newRows, int newColumns) {
	try {
		if (table != nullptr) {
	T** _instance = this->CreateTableInstance(newRows, newColumns);
	oldRows = (oldRows > newRows) ? newRows : oldRows;
	oldColumns = (oldColumns > newColumns) ? newColumns : oldColumns;
	for (int i = 0; i < oldRows; i++) {
		for (int k = 0; k < oldColumns; k++) {
			_instance[i][k] = table[i][k];
		}
	}
	return _instance;
		}
		else {
			throw L"Nullptr exception";
		}
	}
	catch (const wchar_t* a) {
		wprintf(a);
		return nullptr;
	}
}