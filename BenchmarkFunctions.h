#pragma once

#include <iostream>
#include <chrono>
#include <limits>
#include <fstream>
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
		case Selection:
			{
				std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
				SelectionSort(A, size);
				std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
				std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << " microseconds\n";
				return std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count(); 
			}
		case Bubble:
			{
				std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
				BubbleSort(A, size);
				std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
				std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << " microseconds\n";
				return std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count(); 
			}
		case Quick:
			{
				std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
				QuickSort(A, 0, size-1);
				std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
				std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << " microseconds\n";
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
		int tenPercent = arraySize * .1;
		orderArray(A,arrayType, arraySize, Sorted);
		makeRandom(A, arrayType, tenPercent);	
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

//Save Benchmarks into txt file
//Two strings, one with algorithm choice, size, array sorter - second string for standard deviation
void save(std::string data,std::string sdata) {
	
	std::ofstream myfile("benchmarks.txt", std::ios::app);
	
	if(myfile.is_open()){
		
		myfile << data << sdata;
	
		myfile.close();
	}
	else std::cout << "Unable to open file\n";
}

//Takes all benchmark inputs, outputs average and standard deviation at the end of 100 benchmark tests
void Benchmark() {
	
	std::string arrayTypeString, algorithmString, shuffleTypeString;
	
	ArrayType arrayType = setArrayType();
	
	Sorter sorter = setAlgorithm();
	
	BenchArraySize benchArraySize = setBenchArraySize();
	
	BenchShuffleType shuffleType = setBenchShuffleType();
	
	Array<int> arrayToSortInt;
	Array<float> arrayToSortFloat;
	Array<double> arrayToSortDouble;
	Array<int> benchArray;
	
	switch(sorter) {
		case Bubble:
			algorithmString = "bubble";
			break;
		case Insertion:
			algorithmString = "insertion";
			break;
		case Selection:
			algorithmString = "selection";
			break;
		case Merge:
			algorithmString = "merge";
			break;
		case Quick:
			algorithmString = "quick";
			break;
		default:
			algorithmString = "no";
			break;
	}
	
	switch(shuffleType) {
		case Sorted:
			shuffleTypeString = "sorted order";
			break;
		case FullShuffle:
			shuffleTypeString = "fully shuffled";
			break;
		case Reverse:
			shuffleTypeString = "reverse order";
			break;
		case TenPercentUnsorted:
			shuffleTypeString = "ten percent shuffled";
			break;
		default:
			shuffleTypeString = "no sorting order picked";
			break;
	}
	
	switch(arrayType) {
		case Integer:
			arrayToSortInt.SetSize(benchArraySize);
			arrayTypeString = "int";
			break;
		case Float:
			arrayToSortFloat.SetSize(benchArraySize);
			arrayTypeString = "float";
			break;
		case Double:
			arrayToSortDouble.SetSize(benchArraySize);
			arrayTypeString = "double";
			break;
		default:
			break;
	}
	
	switch(arrayType) {
		case Integer:
			for(int i = 0; i < 100; i++){
				orderArray(arrayToSortInt.GetArray(), Integer, benchArraySize, shuffleType);
				benchArray.Insert(sortArray(arrayToSortInt.GetArray(), sorter, benchArraySize));
			}
			break;
		case Float:
			for(int i = 0; i < 100; i++){
				orderArray(arrayToSortFloat.GetArray(), Float, benchArraySize, shuffleType);
				benchArray.Insert(sortArray(arrayToSortFloat.GetArray(), sorter, benchArraySize));
			}
			break;
		case Double:
			for(int i = 0; i < 100; i++){
				orderArray(arrayToSortDouble.GetArray(), Double, benchArraySize, shuffleType);
				benchArray.Insert(sortArray(arrayToSortDouble.GetArray(), sorter, benchArraySize));
			}
			break;
		default:
			break;
	}
	
	std::string data = "The average for " + algorithmString + " sort algorithm while array is " + shuffleTypeString
		+ " with size " + std::to_string(benchArraySize) + " " + arrayTypeString + " array is: "
			+ std::to_string(benchArray.GetAverage()) + " microseconds!\n";
			
	std::string sdata = "The standard deviation is: " + std::to_string(benchArray.GetStandardDeviation()) + "\n";
			
	std::cout << data;
	
	std::cout << sdata;
	
	save(data, sdata);
};