//INSERTION SORT 
template <typename T>
void InsertionSort(T *A, int size)
{
	for (int j = 1; j < size; j++)
	{
		T key = A[j];
		int i = j - 1;
		while (i >= 0 && A[i] > key) {
			A[i+1] = A[i];
			i--;
		}
		A[i+1] = key;
	}
};

//SELECTION SORT
template <typename T>
void SelectionSort(T *A, int size)
{
	int i, j, min_index, temp;
	
	//Move boundary of unsorted sub-array 
	for(i = 0; i < size-1; i++)
	{
		//Find minimum element in unsorted array
		min_index = i;
		for(j = i+1; j < size; j++)
			if(A[j] < A[min_index]) min_index = j;
		
		//Swap minimum element with the first element
		temp = A[min_index];
		A[min_index] = A[i];
		A[i] = temp;
	}
};

//BUBBLE SORT
template <typename T>
void BubbleSort(T *A, int size)
{
	int temp;
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size-1; j++)
		{
			if(A[j] > A[j+1])
			{
				temp = A[j];
				A[j] = A[j+1];
				A[j+1] = temp;
			}
		}
	}
};

//PARTITION + QUICKSORT
template <typename T>
int partition(T *A, int first, int last)
{
	//pivot (Element to be placed at right position
	int pivot = A[first];
	int i = first;
	int j, temp;
	
	for(j = first+1; j < last; j++)
	{
		//If current element is smaller than or
		//equal to pivot
		if(A[j] <= pivot)
		{
			i++; //increment index of smaller element
			//swap values
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	}
	
	//swap
	temp = A[first];
	A[first] = A[i];
	A[i] = temp;
	
	//return index
	return i;
};

template <typename T>
void QuickSort(T *A, int firstIndex, int lastIndex)
{
	if(firstIndex < lastIndex)
	{
		int pivotElement = partition(A, firstIndex, lastIndex);
		
		QuickSort(A, firstIndex, pivotElement);
		QuickSort(A, pivotElement+1, lastIndex);
	}
};