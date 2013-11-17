/**
 * Shellsort, using Shell's increments.
 * The efficiency depends on the choose of increments,
 * here we choose Shell's increments, but there are 
 * better increments
 */
template <typename Comparable>
void shellsort(vector<Comparable> & a)
{
	// generate the increments sequence, every iterator will 
	// sort part of the vector
	for(int gap = a.size() / 2; gap > 0; gap /= 2)
	{
		for(int i = gap; i < a.size(); i++)
		{
			Comparable tmp = a[i];
			int j = i;

			for(; j >= gap && tmp < a[j - gap]; j -= gap)
			{
				a[j] = a[j - gap];
			}
			a[j] = tmp;
		}
	}
}