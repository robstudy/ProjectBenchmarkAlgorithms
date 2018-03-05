#pragma once
#include "DataStructure.h"
template <class T>
class Array:public DataStructure
{
	public:
		//constructor
		Array<T>();
		Array<T>(int);
		//destructor
		~Array<T>();
		
		//Accessors + Modifiers
		int GetSize();
		void SetSize(int);
		T GetElement(int);
		void SetElement(int, T);
		bool Find(T);
		void Delete(T);
		void Insert(T);
		int Search(T);
		void Display();
		
		//Return self
		T* GetArray();
		
	private:
		T* A; //The array
		int size; //the size
};
		
template <class T>
Array<T>::Array()
{
	A = NULL;
	size = 0;
};

template <class T>
Array<T>::Array(int cSize)
{
	size = cSize;
	A = new T[size];
	for (int i = 0; i < size; i++) A[i] = 0;
};

template <class T>
Array<T>::~Array()
{
	delete[] A;
};

template <class T>
int Array<T>::GetSize() { return size; };

template <class T>
void Array<T>::SetSize(int newSize)
{
	delete[] A;
	size = newSize;
	A = new T[size];
	for (int i = 0; i < size; i++) A[i] = 0;
};

template <class T>
T Array<T>::GetElement(int index)
{
	if (index < 0) {
		std::cout << "Index too small\n";
		return 0;
	} 
	else if (index >= size) {
		std::cout << "Index too large\n";
		return 0;
	} 
	else
		return A[index];
};

template <class T>
void Array<T>::SetElement(int index, T data) 
{
	A[index] = data;
};

template <class T>
bool Array<T>::Find(T data) 
{
	for(int i = 0; i < size; i++) 
	{
		if (A[i] == data) {
			return true;
		}
	}
	return false;
};

template <class T>
void Array<T>::Delete(T data)
{
	if(Find(data))
	{
		T* temp = new T[size-1];
		int j = 0;
		for(int i = 0; i < size; i++) 
		{
			if(A[i] != data)
			{
				temp[j] = A[i];
				j++;
			}
		}
		delete[] A;
		A = temp;
	}
};

template <class T>
void Array<T>::Insert(T data)
{
	T* temp = new T[size+1];
	for(int i = 0; i < size; i++)
	{
		temp[i] = A[i];
	}
	temp[size] = data;
	delete[] A;
	A = temp;
	size++;
};

template <class T>
int Array<T>::Search(T data) 
{
	for (int i = 0; i < size; i++) 
	{
		if(A[i] == data)
		{
			return i;
		}
	}
	return -1;
};

template <class T>
void Array<T>::Display()
{
	for(int i = 0; i < size; i++) 
	{
		std::cout << A[i] << " ";
	}
	
	std::cout << '\n';
};

template <class T>
T* Array<T>::GetArray(){
	return A;
};