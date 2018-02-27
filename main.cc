#include <iostream>
#include "Array.h"
#include "SortingAlgorithms.h"

int main() 
{
	std::cout << "Insertion Sort!\n";
	Array<int> newArray(10);
	
	for(int i = 0; i < 10; i++)
	{
		newArray.SetElement(i, rand()%100);
	}
	newArray.Display();
	
	insertionSort(newArray.GetArray(), newArray.GetSize());
	
	newArray.Display();
	
	return 0;
}