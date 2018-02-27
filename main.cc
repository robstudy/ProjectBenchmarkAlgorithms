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
	
	InsertionSort(newArray.GetArray(), newArray.GetSize());
	
	newArray.Display();
	
	std::cout << "Selection Sort!\n";
	for(int i = 0; i < 10; i++)
	{
		newArray.SetElement(i, rand()%100);
	}
	
	newArray.Display();
	
	SelectionSort(newArray.GetArray(), newArray.GetSize());
	
	newArray.Display();
	
	std::cout << "Bubble Sort!\n";
	for(int i = 0; i < 10; i++)
	{
		newArray.SetElement(i, rand()%100);
	}
	
	newArray.Display();
	
	BubbleSort(newArray.GetArray(), newArray.GetSize());
	
	newArray.Display();
	
	std::cout << "Quick Sort!\n";
	for(int i = 0; i < 10; i++)
	{
		newArray.SetElement(i, rand()%100);
	}
	
	newArray.Display();
	
	QuickSort(newArray.GetArray(), 0, newArray.GetSize());
	
	newArray.Display();
	
		
	std::cout << "Merge Sort!\n";
	for(int i = 0; i < 10; i++)
	{
		newArray.SetElement(i, rand()%100);
	}
	
	newArray.Display();
	
	QuickSort(newArray.GetArray(), 0, newArray.GetSize()-1);
	
	newArray.Display();
	return 0;
}