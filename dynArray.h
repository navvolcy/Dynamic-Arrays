#pragma once
#include<string>
using namespace std;

class DynArray {

private: int cap;
		 int Size;
		 int* arr;
		 
public:
       DynArray();
	   DynArray(int n);
	   DynArray(const DynArray& other);
	   DynArray& operator=(const DynArray& other);
	   ~DynArray();
	   int size() const;
	   int capacity() const;
	   void clear();
	   void push_back(const int& n);
	   void pop_back();
	   int& at(int n);
	   int& operator[ ](int index) const;
	   int& front() const;
	   int& back() const;

};



