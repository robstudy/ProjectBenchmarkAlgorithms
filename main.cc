#include <iostream>
#include "Array.h"
#include "BenchmarkFunctions.h"

int main() 
{
	//input
	char input;
	
	std::cout << "Press:\n1. Benchmark\n2. Play with arrays\n";
	
	std::cin >> input;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.clear();
	
	if(input == '1') {
		
		while(true) {
			
			Benchmark();
			
			std::cout << "Benchmark again?\n1. Yes\n2. No\n";
			
			std::cin >> input;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cin.clear();
			
			if(input != '1') return 0;
		}
	}
	
	//enums for sorting and array type;
	ArrayType arrayType;
	Sorter sortAlgorithm;
	BenchShuffleType arraySorter;
	
	//Initialize 3 types of array size 0
	Array<int> intArray;
	Array<float> floatArray;
	Array<double> doubleArray;
	
	//Set Array type
	arrayType = setArrayType();
	
	//Set Sort Type
	arraySorter = setBenchShuffleType();
	
	//Set Sorting Algorithm 
	sortAlgorithm = setAlgorithm();
	
	//Set Size
	BenchArraySize arraySize = setBenchArraySize();
	
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
			break;
	}
	
	//Play loop
	while(true){
		
		std::cout << "Choose the following:\n1. Print Array\n2. Sort Array\n"
			<< "3. Randomize Array\n4. Set Sorter\n5. Choose Different Algorithm\n"
			<< "6. New Array Size\n7. Benchmark\n8. Quit\n";
		
		std::cin >> input;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin.clear();
		
		switch(input) {
			case '1':
				if(arrayType == Integer) intArray.Display();
				else if(arrayType == Float) floatArray.Display();
				else if(arrayType == Double) doubleArray.Display();
				break;
			case '2':
				if(arrayType == Integer) sortArray(intArray.GetArray(), sortAlgorithm, arraySize);
				else if(arrayType == Float) sortArray(floatArray.GetArray(), sortAlgorithm, arraySize);
				else if(arrayType == Double) sortArray(doubleArray.GetArray(), sortAlgorithm, arraySize);
				break;
			case '3':
				if(arrayType == Integer) orderArray(intArray.GetArray(), arrayType, arraySize, arraySorter);
				else if(arrayType == Float) orderArray(floatArray.GetArray(), arrayType, arraySize, arraySorter);
				else if(arrayType == Double) orderArray(doubleArray.GetArray(), arrayType, arraySize, arraySorter);
				break;
			case '4':
				arraySorter = setBenchShuffleType();
				break;
			case '5':
				sortAlgorithm = setAlgorithm();
				break;
			case '6':
				arraySize = setBenchArraySize();
				if(arrayType == Integer) intArray.SetSize(arraySize);
				else if(arrayType == Float) floatArray.SetSize(arraySize);
				else if(arrayType == Double) doubleArray.SetSize(arraySize);
				break;
			case '7':
				Benchmark();
				break;
			case '8':
				return 0;
			default:
				break;
		}
	}
};