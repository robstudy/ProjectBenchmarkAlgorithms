#include <iostream>
#include <algorithm>
#include <ctime>
#include <chrono>
#include "Array.h"
#include "BenchmarkFunctions.h"

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
	
	//Set Sorting Algorithm 
	sortAlgorithm = setAlgorithm();
	
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
		std::cout << "Choose the following:\n1. Benchmark\n2. Print Array\n3. Randomize Array\n4. Sort Array\n5. Choose Different Algorithm\n6. Quit\n";
		std::cin >> input;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		switch(input) {
			case '5':
				sortAlgorithm = setAlgorithm();
				break;
			case '1':
				Benchmark();
				break;
			case '2':
				if(arrayType == Integer) intArray.Display();
				else if(arrayType == Float) floatArray.Display();
				else if(arrayType == Double) doubleArray.Display();
				break;
			case '3':
				if(arrayType == Integer) makeRandom(intArray.GetArray(), arrayType, arraySize);
				else if(arrayType == Float) makeRandom(floatArray.GetArray(), arrayType, arraySize);
				else if(arrayType == Double) makeRandom(doubleArray.GetArray(), arrayType, arraySize);
				break;
			case '4':
				if(arrayType == Integer) sortArray(intArray.GetArray(), sortAlgorithm, arraySize);
				else if(arrayType == Float) sortArray(floatArray.GetArray(), sortAlgorithm, arraySize);
				else if(arrayType == Double) sortArray(doubleArray.GetArray(), sortAlgorithm, arraySize);
				break;
			case '6':
				playLoop = false;
			default:
				break;
		}
	}
	
	return 0;
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