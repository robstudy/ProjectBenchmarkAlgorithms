#pragma once

#include <iostream>
#include <algorithm>
#include <ctime>
#include <chrono>
#include <limits>
#include "SortingAlgorithms.h"
#include "Array.h"

enum Sorter { Insertion, Selection, Bubble, Quick, Merge };
enum ArrayType { Char, Integer, Float, Double };

template <typename T>
void makeRandom(T *A, ArrayType arrayType, int size) {
	int i;
	switch(arrayType){
		case Char:
			for(i = 0; i < size; i++) A[i] = 'a' + rand() % ('Z' - 'a' + 1);
			break;
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
void sortArray(T *A, Sorter sortAlgorithm, int size) {
	switch(sortAlgorithm) {
		case Insertion:
			{
				std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
				std::chrono::steady_clock::time_point end= std::chrono::steady_clock::now();
				InsertionSort(A, size);
				std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() <<std::endl;
				std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() <<std::endl;
			}
			break;
		case Selection:
			SelectionSort(A, size);
			break;
		case Bubble:
			BubbleSort(A, size);
			break;
		case Quick:
			QuickSort(A, 0, size);
			break;
		case Merge:
			MergeSort(A, 0, size-1);
			break;
		default:
			break;
	}
};	