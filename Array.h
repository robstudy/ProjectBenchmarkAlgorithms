#pragma once

template <class T>
class Array
{
	public:
		//constructor
		Array<T>();
		Array(int n);
		//destructor
		~Array();
		
		//Accessors + Modifiers
		unsigned int GetSize();
		int GetElement(int);
		void SetElement(int, int);
		bool Find(int);
		void Delete(int);
		void Insert(int);
		T Search(int);
		void Display();
		
	private:
		T* A; //The array
		unsigned int size; //the size
};
		