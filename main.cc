#include <iostream>
#include "Array.h"
#include "SortingAlgorithms.h"

enum Sorter { Insertion, Selection, Bubble, Quick, Merge };
enum ArrayType { Char, Integer, Float, Double };

ArrayType setArrayType();

int main() 
{
	//input
	char input;
	int arraySize;
	
	//enums for sorting and array type;
	ArrayType arrayType;
	Sorter sortAlgorithm;
	Array<char> charArray;
	Array<int> intArray;
	Array<float> floatArray;
	Array<double> doubleArray;
	
	arrayType = setArrayType();
	
	if(arrayType == Char){
		
	} 
	else if(arrayType == Integer) {
		intArray.SetSize(10);
	}
	
	return 0;
};

//Select Array Type
ArrayType setArrayType()
{
	char input;
	bool selectionArrayType = true;
	while(selectionArrayType) 
	{
		std::cout << "Select array type 'c', 'i', 'f', 'd'; Char, Int, Float, Double\n";
		std::cin >> input;
		switch(input){
			case 'c':
				std::cout << "Array is char!\n";
				return Char;
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