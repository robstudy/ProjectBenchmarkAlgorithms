#pragma once

#include <iostream>
#include <chrono>
#include <limits>
#include "SortingAlgorithms.h"
#include "Array.h"

//Enums to keep track benchmarking states
enum Sorter { Insertion, Selection, Bubble, Quick, Merge };

enum ArrayType { Integer, Float, Double };

enum BenchArraySize { Ten = 10, Thousand = 1000, TenThousand = 10000, HThousand = 100000, Million = 1000000 };

enum BenchShuffleType { Sorted, FullShuffle, Reverse, TenPercentUnsorted };

//Make array random, can rand Int, Float, Double
template <typename T>
void makeRandom(T *A, ArrayType arrayType, int size) {
	
	int i;
	
	switch(arrayType){
		case Integer:
			for(i = 0; i < size; i++) A[i] = rand()%100;
			break;
		case Float:
			for(i = 0; i < size; i++) A[i] = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/100));
			break;
		case Double:
			for(i = 0; i < size; i++) A[i] = static_cast <double> (rand()) / (static_cast <double> (RAND_MAX/100));
			break;
		default:
			std::cout << "Error no size chosen\n";
			break;
	}
};	

//Function Sends array to sorting algorithms and returns the time in microseconds of runtime 
//Outputs microsecond time 
//Time measured with chrono steady_clock
template <typename T>
int sortArray(T *A, Sorter sortAlgorithm, int size) {
	
	switch(sortAlgorithm) {
		case Insertion:
			{
				std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
				InsertionSort(A, size);
				std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
				std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << " microseconds\n";
				return std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count(); 
			}
			break;
		case Selection:
			{
				std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
				SelectionSort(A, size);
				std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
				std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << " microseconds\n";
				return std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count(); 
			}
			break;
		case Bubble:
			{
				std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
				BubbleSort(A, size);
				std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
				std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << " microseconds\n";
				return std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count(); 
			}
			break;
		case Quick:
			{
				std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
				QuickSort(A, 0, size);
				std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
				std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << " nanosecond\n";
				return std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() ;
			}
			break;
		case Merge:
			{
				std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
				MergeSort(A, 0, size-1);
				std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
				std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << " microseconds\n";
				return std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
			}
			break;
		default:
			break;
	}
};	

//Order the array based on the benchtype = Sorted, FullShuffle, Reverse or TenPercentUnsorted
template <typename T>
void orderArray(T *A, ArrayType arrayType, BenchArraySize arraySize, BenchShuffleType benchType) {
	
	int i;
	
	if (benchType == Sorted) {
		
		switch(arrayType){
			case Integer:
				for(i = 0; i < arraySize; i++) A[i] = i;
				break;
			case Float:
				for(i = 0; i < arraySize; i++) A[i] = static_cast <float> (i);
				break;
			case Double:
				for(i = 0; i < arraySize; i++) A[i] = static_cast <double> (i);
				break;
			default:
				std::cout << "Error no size chosen\n";
				break;
		}
	} 
	else if (benchType == FullShuffle) {
		
		makeRandom(A, arrayType, arraySize);
	}
	else if (benchType == Reverse) {
		
		switch(arrayType){
			case Integer:
				for(i = 0; i < arraySize; i++) A[i] = arraySize - i;
				break;
			case Float:
				for(i = 0; i < arraySize; i++) A[i] = static_cast <float> (arraySize - i);
				break;
			case Double:
				for(i = 0; i < arraySize; i++) A[i] = static_cast <double> (arraySize - i);
				break;
			default:
				std::cout << "Error no size chosen\n";
				break;
		}
	}
	else if ( benchType == TenPercentUnsorted) {
		orderArray(A,arrayType, arraySize, Sorted);
		makeRandom(A, arrayType, arraySize%10);	
	}
};

//Input takes choice of which sorting algorithm to use, returns enum type Bubble, Insertion, Selection, Merge, Quick
Sorter setAlgorithm(){
	
	std::cout << "Choose an algorithm to benchmark:\n1. Bubble\n2. Insertion\n3. Selection\n4. Merge\n5. Quick\n";
	
	char input;
	
	std::cin >> input;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.clear();
	
	switch (input){
		case '1':
			return Bubble;
		case '2':
			return Insertion;
		case '3':
			return Selection;
		case '4':
			return Merge;
		case '5':
			return Quick;
		default:
			return Quick;
	}
};

//Input takes cases 1 - 5
//Returns enum type for array sizes 10, 1000, 10000, 100000, 1000000 - Ten, Thousand, TenThousand, HThousand, Million
BenchArraySize setBenchArraySize(){
	
	std::cout << "Choose an array size\n1. 10\n2. 1000\n3. 10000\n4. 100000\n5. 1000000\n";
	
	char input;
	
	std::cin >> input;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.clear();
	
	switch(input) {
		case '1':
			return Ten;
		case '2':
			return Thousand;
		case '3':
			return TenThousand;
		case '4':
			return HThousand;
		case '5':
			return Million;
		default:
			return Ten;
	}
};

//Set BenchShuffleType Sorted, FullShuffle, Reverse, TenPercentUnsorted and return it
BenchShuffleType setBenchShuffleType(){
	
	char input;
	
	std::cout << "Choose shuffle type:\n1. Sorted\n2. FullShuffle\n3. Reverse\n4. TenPercentUnsorted\n";
	
	std::cin >> input;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.clear();
	
	switch(input) {
		case '1':
			return Sorted;
		case '2':
			return FullShuffle;
		case '3': 
			return Reverse;
		case '4':
			return TenPercentUnsorted;
		default:
			return FullShuffle;
	}
};

//Set ArrayType to Integer, Float, or Double
ArrayType setArrayType() {
	
	int input;
	
	std::cout << "Choose array type:\n1. Integer\n2. Float\n3. Double\n";
	
	std::cin >> input;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.clear();
	
	switch(input) {
		case 1:
			return Integer;
		case 2:
			return Float;
		case 3:
			return Double;
		default:
			return Integer;
	}
};

//Takes all benchmark inputs, outputs average and standard deviation at the end of 100 benchmark tests
void Benchmark() {
	
	//ArrayType arrayType = setArrayType();
	
	Sorter sorter = setAlgorithm();
	
	BenchArraySize benchArraySize = setBenchArraySize();
	
	BenchShuffleType shuffleType = setBenchShuffleType();
	
	Array<int> arrayToSort;
	
	Array<int> benchArray;
	
	arrayToSort.SetSize(benchArraySize);
	
	for(int i = 0; i < 100; i++){
		
		orderArray(arrayToSort.GetArray(), Integer, benchArraySize, shuffleType);
		
		benchArray.Insert(sortArray(arrayToSort.GetArray(), sorter, benchArraySize));
	}
	
	std::cout << "The average for this sorting algorithm is : " << benchArray.GetAverage() << std::endl;
	
	std::cout << "The standard deviation is : " << benchArray.GetStandardDeviation() << std::endl;
};