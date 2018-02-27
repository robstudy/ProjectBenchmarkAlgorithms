//INSERTION SORT 
template <typename T>
void insertionSort(T *A, int size)
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