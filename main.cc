#include <iostream>
#include <algorithm>
#include <ctime>
#include <chrono>
#include "Array.h"
#include "BenchmarkFunctions.h"

ArrayType setArrayType();
Sorter setSorter();
int setArraySize();

int main() 
{
	//input
	char input;
	
	std::cout << "Press 1 to go straight to benchmark test or enter anything to play with array and sorting algorithms\n";
	
	std::cin >> input;
	
	if(input == '1') {
		
		while(true) {
			
			Benchmark();
			
			std::cout << "Benchmark again?\n1. Yes\n2. No\n";
			
			std::cin >> input;
			
			if(input != '1') return 0;
		}
	}
		
	int arraySize;
	
	//For input while loop
	bool playLoop = true;
	
	//enums for sorting and array type;
	ArrayType arrayType;
	Sorter sortAlgorithm;
	
	//Initialize 4 types of array size 0
	Array<int> intArray;
	Array<float> floatArray;
	Array<double> doubleArray;
	
	//Set Array type
	arrayType = setArrayType();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.clear();
	
	//Set Sorting Algorithm 
	sortAlgorithm = setAlgorithm();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.clear();
	
	//Set Size
	arraySize = setArraySize();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.clear();
	
	
	switch(arrayType){
		case Integer:
			intArray.SetSize(arraySize);
			break;
		case Float:
			floatArray.SetSize(arraySize);
			break;
		case Double:
			doubleArray.SetSize(arraySize);
			break;
		default:
			std::cout << "Error no size chosen\n";
			break;
	}
	
	//Play loop
	while(playLoop){
		std::cout << "Choose the following:\n'b':Benchmark\n'p':Print Array\n'r':Randomize Array\n's':Sort Array\n'c':Choose Different Algorithm\n'q':Quit\n";
		std::cin >> input;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		switch(input) {
			case 'c':
				sortAlgorithm = setSorter();
				break;
			case 'b':
				Benchmark();
				break;
			case 'p':
				if(arrayType == Integer) intArray.Display();
				else if(arrayType == Float) floatArray.Display();
				else if(arrayType == Double) doubleArray.Display();
				break;
			case 'r':
				if(arrayType == Integer) makeRandom(intArray.GetArray(), arrayType, arraySize);
				else if(arrayType == Float) makeRandom(floatArray.GetArray(), arrayType, arraySize);
				else if(arrayType == Double) makeRandom(doubleArray.GetArray(), arrayType, arraySize);
				break;
			case 's':
				if(arrayType == Integer) sortArray(intArray.GetArray(), sortAlgorithm, arraySize);
				else if(arrayType == Float) sortArray(floatArray.GetArray(), sortAlgorithm, arraySize);
				else if(arrayType == Double) sortArray(doubleArray.GetArray(), sortAlgorithm, arraySize);
				break;
			case 'q':
				playLoop = false;
			default:
				break;
		}
	}
	
	return 0;
};

//Select Array Type
ArrayType setArrayType()
{
	char input;
	while(true) 
	{
		std::cout << "Select array type:\n'i':Int\n'f':Float\n'd':Double\n";
		std::cin >> input;
		switch(input){
			case 'i':
				std::cout << "Array is int!\n";
				return Integer;
			case 'f':
				std::cout << "Array is float!\n";
				return Float;
			case 'd':
				std::cout << "Array is double!\n";
				return Double;
			default:
				break;
		}
	}
};

//Set Sorting Algorithm 
Sorter setSorter() 
{
	char input;
	while(true)
	{
		std::cout << "Select soring algorithm:\n'i':Insertion\n's':Selection\n'b':Bubble\n'q':Quick\n'm':Merge\n";
		std::cin >> input;
		switch(input){
			case 'i':
				std::cout << "Insertion Sort selected!\n";
				return Insertion;
			case 's':
				std::cout << "Selection Sort selected!\n";
				return Selection;
			case 'b':
				std::cout << "Bubble Sort selected!\n";
				return Bubble;
			case 'q':
				std::cout << "Quick Sort selected!\n";
				return Quick;
			case 'm':
				std::cout << "Merge Sort selected!\n";
				return Merge;
			default:
			break;
		}
	}
};

//Set Array Size
int setArraySize() {
	int input;
	while(true)
	{
		std::cout << "Enter a valid array size!\n";
		std::cin >> input;
		if(input < 0) continue;
		std::cout << "Array size set to " << input << std::endl;
		return input;
	}
};