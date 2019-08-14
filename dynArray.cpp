#include "dynarray.h"
#include <iostream>


DynArray::DynArray()
{
	cap = 2;
	Size = 0;
	arr = new int[cap];
}

DynArray::DynArray(int n)
{
	cap = n;
	Size = 0;
	arr = new int[cap];
}

DynArray::DynArray(const DynArray& other)
{
   
	cap = other.capacity(); 
	Size = other.size();
	arr = new int[cap];
	for (int i = 0; i < other.size(); i++) {
		arr[i] = other[i];
	}


}

	
DynArray& DynArray::operator=(const DynArray& other)
{
	
	if (this == &other) return*this;
	delete[]arr;
	arr = new int[other.capacity()];
	Size = other.size();
	cap = other.capacity();
	for (int i = 0; i < other.size(); i++) {
		arr[i] = other[i];
	}
	return*this;


}



DynArray::~DynArray()
{
	
	delete [] arr;
	
}

int DynArray::size() const
{
	return Size;
}

int DynArray::capacity() const
{
	return cap;
}

void DynArray::clear()
{
	delete[] arr;
	cap = 2;
	Size = 0;
	arr = new int[cap];

}

void DynArray::push_back(const int& n)
{
	if (Size == cap) {
		int*temp = new int[cap * 2];
		for (int i = 0; i < Size; i++) {
			temp[i] = arr[i];
		}
		cap = cap * 2;
		delete arr;
		arr = temp;
		temp = NULL;
		delete temp;
		
	}
	arr[Size] = n;
	
	Size = Size + 1;
}

void DynArray::pop_back()
{
	if (Size == 0) {
		throw runtime_error("array is empty");

}
	else
	{
		Size = Size - 1;
	}
}

int& DynArray::at(int n)
{
	if (n >= Size || n < 0) {
		throw runtime_error("invalid index");
	}
	else {
		return arr[n];
	}
}

int& DynArray::operator[](int index) const
{
	if (index > Size || index < 0) {
		return arr[0];
	}
	else {
		return arr[index];
	}
}

int& DynArray::front() const
{
	if (Size == 0) {
		throw runtime_error(" the array is empty");

	}
	else {
		return arr[0];
	}
	
}

int& DynArray::back() const
{
	if (Size == 0) {
		throw runtime_error("the array is empty");
	}
	else {
		return arr[Size-1];
	}
}
