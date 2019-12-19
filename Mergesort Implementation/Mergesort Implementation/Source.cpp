#include <vector>

// Mergesort algorithm (driver)
template <typename Comparable>
void mergesort(std::vector<Comparable>& a)
{
	std::vector<Comparable> tmpArray(a.size());

	mergeSort(a, tmpArray, 0, a.size() - 1);
}

// Internal method that makes recursive calls.
// a is an array of Comparable items. tmpArray is an array to place the merged result.
// left is the left-most index of the subarray.
// right is the right-most index of the subarray.
template <typename Comparable>
void mergeSort(std::vector<Comparable>& a, std::vector<Comparable>& tmpArray, int left, int right)
{
	if (left < right)
	{
		int center = (left + right) / 2;
		mergeSort(a, tmpArray, left, center);
		mergeSort(a, tmpArray, center + 1, right);
		merge(a, tmpArray, left, center + 1, right);
	}
}

// Internal method that merges two sorted halves of a subarray.
// a is an array of Comparable items. tmpArray is an array to place the merged result.
// leftPos is the left-most index of the subarray. rightPos is the start of the second half.
// rightEnd is the right-most index of the subarray.
template <typename Comparable>
void merge(std::vector<Comparable>& a, std::vector<Comparable>& tmpArray, int leftPos, int rightPos, int rightEnd)
{
	int leftEnd = rightPos - 1;
	int tmpPos = leftPos;
	int numElements = rightEnd - leftPos + 1;

	// Main loop
	while (leftPos <= leftEnd && rightPos <= rightEnd)
	{
		if (a[leftPos] <= a[rightPos])
		{
			tmpArray[tmpPos++] = std::move(a[leftPos++]);
		}
		else
		{
			tmpArray[tmpPos++] = std::move(a[rightPos++]);
		}

		// Copy rest of first half.
		while (leftPos <= leftEnd)
		{
			tmpArray[tmpPos++] = std::move(a[leftPos++]);
		}

		// Copy rest of right half.
		while (rightPos <= rightEnd)
		{
			tmpArray[tmpPos++] = std::move(a[rightPos++]);
		}

		// Copy tmpArray back.
		for (int i = 0; i < numElements; ++i, --rightEnd)
		{
			a[rightEnd] = std::move(tmpArray[rightEnd]);
		}
	}
}

int main()
{
	return 0;
}