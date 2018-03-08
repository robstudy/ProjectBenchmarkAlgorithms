#pragma once

#include <iostream>
#include <chrono>
#include "SortingAlgorithms.h"
#include "Array.h"

enum Sorter { Insertion, Selection, Bubble, Quick, Merge };
enum ArrayType { Integer, Float, Double };
enum BenchArraySize { Ten = 10, Thousand = 1000, TenThousand = 10000, HThousand = 100000, Million = 1000000 };
enum BenchArrayType { Sorted, FullShuffle, Reverse, TenPercentUnsorted };

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

template <typename T>
void orderArray(T *A, ArrayType arrayType, BenchArraySize arraySize, BenchArrayType benchType) {
	int i;
	if ( benchType == Sorted ) {
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
	else if ( benchType == FullShuffle ) {
		makeRandom(A, arrayType, benchType);
	}
	else if ( benchType == Reverse) {
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
		makeRandom(A, arrayType, benchType%10);	
	}
};

Sorter setAlgorithm(){
	
	std::cout << "Choose an algorithm to benchmark:\nb:Bubble\ni:Insertion\ns:Selection\nm:Merge\nq:Quick\n";
	
	char input;
	
	std::cin >> input;
	
	switch (input){
		case 'b':
			return Bubble;
		case 'i':
			return Insertion;
		case 's':
			return Selection;
		case 'm':
			return Merge;
		case 'q':
			return Quick;
		default:
			setAlgorithm();
	}
};

BenchArraySize setBenchArraySize(){
	
	std::cout << "Choose an array size\n'1':10\'2':1000\n'3':10000\n'4'.100000\n'5'1000000\n";
	
	int input;
	
	std::cin >> input;
	
	switch(input) {
		case 1:
			return Ten;
		case 2:
			return Thousand;
		case 3:
			return TenThousand;
		case 4:
			return HThousand;
		case 5:
			return Million;
		default:
			setBenchArraySize();
	}
};

void Benchmark() {
	
	Sorter sorter = setAlgorithm();
	BenchArraySize benchSize = setBenchArraySize();
	char input;
	bool benching = true;
	Array<int> arrayToSort;
	Array<int> benchArray;
	
	arrayToSort.SetSize(benchSize);
	
	for(int i = 0; i < 100; i++){
		makeRandom(arrayToSort.GetArray(), Integer, benchSize);
		benchArray.Insert(sortArray(arrayToSort.GetArray(), sorter, benchSize));
	}
	
	std::cout << "The average for this sorting algorithm is : " << benchArray.GetAverage() << std::endl;
	std::cout << "The standard deviation is : " << benchArray.GetStandardDeviation() << std::endl;
}