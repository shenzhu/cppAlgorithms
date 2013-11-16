/**
 * Quicksort algorithm
 */
template <typename Comparable>
void quicksort(vector<Comparable> & a)
{
	quicksort(a, 0, a.size() - 1);
}

/**
 * Return median of left, center and right.
 * Order these and hide the pivot
 */
template <typename Comparable>
const Comparable & median3(vector<Comparable> & a, int left, int right)
{
	int center = (left + right) / 2;
	if(a[center] < a[left])
		swap(a[left], a[center]);
	if(a[right] < a[left])
		swap(a[left], a[right]);
	if(a[right] < a[center])
		swap(a[center], a[right]);

	// place pivot at position right - 1
	swap(a[center], a[right - 1]);
	return a[right - 1];
}

/**
 * Internal quicksort method that makes recursive calls.
 * Uses median-of-three partitioning and a cutoff of 10.
 * a is an array of Comparable items.
 * left is the left-most index of the subarray.
 * right is the right-most index of the subarray.
 */
template <typename Comparable>
void quicksort(vector<Comparable> & a, int left, int right)
{
	// calculate the number of elements, for array that has the number
	// less than 10, insertion sort is better than quicksort(recurse)
	if(left + 10 <= right)
	{
		Comparable pivot = median3(a, left, right);
		
		// begin partitioning 
		int i = left, j = right - 1;
		for(;;)
		{
			while(a[++i] < pivot){}
			while(pivot < a[--j]){}
			if(i < j)
				swap(a[i], a[j]);
			else
				break;
		}

		swap(a[i], a[right - 1]); // restore pivot

		quicksort(a, left, i - 1); // sort small elements
		quicksort(a, i + 1, right); // sort large elements
	}
	else 
		// use insertionsort on the subarray
		insertionSort(a, left, right);
}

