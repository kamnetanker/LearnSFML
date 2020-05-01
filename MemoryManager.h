#pragma once
#ifndef _MMG_
#define _MMG_
#endif // !_MMG_

#ifndef NULL
#define NULL 0
#endif // !NULL
template <typename T>
class MemoryManager {
public:
	MemoryManager();
	T CreateInstance();
	T* CreatePointerInstance();
	T* CreateArrayInstance(int length);
	T** CreateTableInstance(int rows,int columns);
	T* ResizeArrayInstance(T* array, int oldLength, int newLength);
	T** ResizeTableInstance(T** table, int oldRows, int oldColumns, int newRows, int newColumns);
private:  
protected:
};
