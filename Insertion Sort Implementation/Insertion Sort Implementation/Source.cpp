#include <vector>
#include <iostream>

// Simple insertion sort.
template <typename Comparable>
void insertionSort(std::vector<Comparable>& a)
{
	for (int p = 1; p < a.size(); ++p)
	{
		Comparable tmp = std::move(a[p]);

		int j;
		for (j = p; j > 0 && tmp < a[j - 1]; --j)
		{
			a[j] = std::move(a[j - 1]);
		}

		a[j] = std::move(tmp);
	}
}

// The two parameter version calls the three-parameter version using C++11 decltype
template <typename Iterator>
void insertionSort(const Iterator& begin, const Iterator& end)
{
	insertionSort(begin, end, std::less<decltype(*begin)>{});
}

// The three parameter version.
template <typename Iterator, typename Comparator>
void insertionSort(const Iterator& begin, const Iterator& end, Comparator lessThan)
{
	if (begin == end)
	{
		return; // Empty, do nothing.
	}

	Iterator j; // Create an iterator object named j.

	for (Iterator p = begin + 1; p != end; ++p)
	{
		auto tmp = std::move(*p);
		for (j = p; j != begin && lessThan(tmp, *(j - 1)); --j)
		{
			*j = std::move(*(j - 1));
		}

		*j = std::move(tmp);
	}
}

int main()
{
	return 0;
}