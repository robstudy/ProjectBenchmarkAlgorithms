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
		for(int j = 0; j < (size-1-i); j++)
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
	int pivot = A[last];
	int i = (first-1);
	int j, temp;
	
	for(j = first; j <= (last-1); j++)
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
	temp = A[last];
	A[last] = A[i+1];
	A[i+1] = temp;
	
	//return index
	return (i+1);
};

template <typename T>
void QuickSort(T *A, int firstIndex, int lastIndex)
{
	if(firstIndex < lastIndex)
	{
		int pivotElement = partition(A, firstIndex, lastIndex);
		
		QuickSort(A, firstIndex, pivotElement-1);
		QuickSort(A, pivotElement+1, lastIndex);
	}
};

//MERGE and MERGESORT
template <typename T>
void merge(T *A, int low, int mid, int high)
{
	int i, j, k;
	int n1 = mid - low + 1;
	int n2 = high - mid;
	
	//temp arrays left and right
	T* L = new T[n1];
	T* R = new T[n2];
	
	//Copy data temp arrays L[] and R[]
	for(i = 0; i < n1; i++)
		L[i] = A[low+i];
	for(j = 0; j < n2; j++)
		R[j] = A[mid+1+j];
	
	//Merge the temp arrays back into A[low..high]
	i = 0; //Initial index of first sub-array
	j = 0; //Initial index of second sub-array
	k = low; //Initial index of merged sub-array
	
	while(i < n1 && j < n2)
	{
		if(L[i] <= R[j])
		{
			A[k] = L[i];
			i++;
		}
		else 
		{
			A[k] = R[j];
			j++;
		}
		k++;
	}
	
	//Copy the remaining elements of L[], if there are any
	while(i < n1)
	{
		A[k] = L[i];
		i++; 
		k++;
	}
	
	//Copy the remaining elements of R[], if there are any
	while(j < n2)
	{
		A[k] = R[j];
		j++;
		k++;
	}
	
	delete[] R;
	delete[] L;
};

template <typename T>
void MergeSort(T *A, int low, int high)
{
	int mid;
	
	//Check for base case
	if(low < high)
	{
		//First, divide in half
		mid = low + (high - low)/2;
		
		//First recursive call
		MergeSort(A, low, mid);
		//Second recursive call
		MergeSort(A, mid+1, high);
		//The merge function call
		merge(A, low, mid, high);
	}
};