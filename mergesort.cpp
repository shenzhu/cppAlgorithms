/**
 * Mergesor algorithm
 */
template <typename Comparable>
void mergeSort(vector<Comparable> & a)
{
	// allocate a temporary array 
	vector<Comparable> tmpArray(a.size());
	mergeSort(a, tmpArray, 0, a.size() - 1);
}

/**
 * Internal method that makes recursive calls.
 * a is an array of Comparable items.
 * tmpArray is an array to place the merged result.
 * left is the left-most index of the subarray.
 * right is the right-most index of the subarray.
 */
template <typename Comparable>
void mergeSort(vector<Comparable> & a,
			   vector<Comparable> & tmpArray,
			   int left, int right)
{
	if(left < right)
	{
		int center = (left + right) / 2;
		mergeSort(a, tmpArray, left, center);
		mergeSort(a, tmpArray, center + 1, right);
		merge(a, tmpArray, left, center + 1, right);
	}
}

/**
 * Internal method that merges two sorted halves of a subarray.
 * a is an array of Comparable items.
 * tmpArray is an array to place the merged result.
 * leftPos is the left-most index of the subarray.
 * rightPos is the index of the start of the second half.
 * rightEnd is the right-most index of the subarray.
 */
template <typename Comparable>
// the parameters are always a and temArray, the only thing that 
// chages is the index of elements
void merge(vector<Comparable> & a,
		   vector<Comparable> & tmpArray,
		   int leftPos,
		   int rightPos,
		   int rightEnd)
{
	int leftEnd = rightPos - 1;
	int tmpPos = leftPos;
	// number of elements needs to handle in this merge
	int numElements = rightEnd - leftPos + 1;

	//main loop
	while(leftPos <= leftEnd && rightPos <= rightEnd)
	{
		if(a[leftPos] <= a[rightPos])
		{
			tmpArray[tmpPos++] = a[leftPos++];
		}else{
			tmpArray[tmpPos++] = a[rightPos++];
		}
	}

	// the two while clauses here can be written in one if clause
	while(leftPos <= leftEnd)// copy the rest of left half
		tmpArray[tmpPos++] = a[leftPos++];

	while(rightPos <= rightEnd)// copy the rest of right half
		tmpArray[tmpPos++] = a[rightPos++];

	// copy tmpArray back
	for(int i = 0; i < numElements; i++, rightEnd--)
		a[rightEnd] = tmpArray[rightEnd];
}

