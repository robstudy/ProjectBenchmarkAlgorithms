//SWAP index
template <typename T>
void swap(T* A, int i, int j)
{
	T tmp = A[i];
	A[i] = A[j];
	A[j] = tmp;
};

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
	int i, j, min_index;
	
	//Move boundary of unsorted sub-array 
	for(i = 0; i < size-1; i++)
	{
		//Find minimum element in unsorted array
		min_index = i;
		for(j = i+1; j < size; j++)
			if(A[j] < A[min_index]) min_index = j;
		
		//Swap minimum element with the first element
		swap(A, i, min_index);
	}
};

//BUBBLE SORT
template <typename T>
void BubbleSort(T *A, int size)
{
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < (size-1-i); j++)
		{
			if(A[j] > A[j+1])
			{
				swap(A, j, (j+1));
			}
		}
	}
};

//PARTITION + QUICKSORT
template <typename T>
int partition(T *A, int first, int last)
{
	//mid pivot avoids worst case scenario 
	int pivot = first + (last-first)/2;
	swap(A, pivot, last);
	for(int i = first; i <last; i++)
	{
		if(A[i] <= A[last])
		{
			swap(A, first, i);
			first++;
		}
	}
	swap(A, first, last);
	return first;
};

template <typename T>
void QuickSort(T *A, int firstIndex, int lastIndex)
{
	if(firstIndex < lastIndex)
	{	
		int pivot = partition(A, firstIndex, lastIndex);
		QuickSort(A, firstIndex, pivot-1);
		QuickSort(A, pivot+1, lastIndex);
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