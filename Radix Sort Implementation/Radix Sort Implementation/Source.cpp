#include <vector>
#include <string>

// One application of radix sort is sorting strings. 
// If all the strings have the same length L, then by using buckets for each character, we can implement a radix sort in O(NL) time.

// Radix sort an array of strings. Assume all are ASCII. Assume all have same length.
void radixSortA(std::vector<std::string>& arr, int stringLen)
{
	const int BUCKETS = 256;
	std::vector<std::vector<std::string>> buckets(BUCKETS);

	for (int pos = stringLen - 1; pos >= 0; --pos)
	{
		for (std::string& s : arr)
		{
			buckets[s[pos]].push_back(std::move(s));
		}

		int idx = 0;
		for (auto& thisBucket : buckets)
		{
			for (std::string& s : thisBucket)
			{
				arr[idx++] = std::move(s);
			}

			thisBucket.clear();
		}
	}
}

// Counting radix sort an array of strings. Assume all are ASCII. Assume all have same length.
void countingRadixSort(std::vector<std::string>& arr, int stringLen)
{
	const int BUCKETS = 256;

	int N = arr.size();
	std::vector<std::string> buffer(N);

	std::vector<std::string>* in = &arr;
	std::vector<std::string>* out = &buffer;

	for (int pos = stringLen - 1; pos >= 0; --pos)
	{
		std::vector<int> count(BUCKETS + 1);

		for (int i = 0; i < N; ++i)
		{
			++count[(*in)[i][pos] + 1];
		}

		for (int b = 1; b <= BUCKETS; ++b)
		{
			count[b] += count[b - 1];
		}

		for (int i = 0; i < N; ++i)
		{
			(*out)[count[(*in)[i][pos]]++] = std::move((*in)[i]);
		}

		// Swap in and out roles.
		std::swap(in, out);
	}

	// If odd number of passes, in is buffer, out is arr; so move back.
	if (stringLen % 2 == 1)
	{
		for (int i = 0; i < arr.size(); ++i)
		{
			(*out)[i] = std::move((*in)[i]);
		}
	}
} //Generally, counting radix sort is prefereable to using vectors to store buckets, but it can suffer from poor locality 
// (out is filled in non-sequentially) and thus, surprisingly, it is not always faster than using a vector of vectors.

// We can extend either version of radix sort to work with variable-length strings. 
// The basic algorithm is to first sort the strings by their length. 
// Instead of looking at all the strings, we can then look only at strings that we know are long enough. 
// Since the string lengths are small numbers, the initial sort by length can be done by—bucket sort!

// Radix sort an array of strings. Assume all are ASCII. Assume all have length bounded by maxLen
void radixSort(std::vector<std::string>& arr, int maxLen)
{
	const int BUCKETS = 256;

	std::vector<std::vector<std::string>> wordsByLength(maxLen + 1);
	std::vector<std::vector<std::string>> buckets(BUCKETS);

	for (std::string& s : arr)
	{
		wordsByLength[s.length()].push_back(std::move(s));
	}

	int idx = 0;
	for (auto& wordList : wordsByLength)
	{
		for (std::string& s : wordList)
		{
			arr[idx++] = std::move(s);
		}
	}

	int startingIndex = arr.size();
	for (int pos = maxLen - 1; pos >= 0; --pos)
	{
		startingIndex -= wordsByLength[pos + 1].size();

		for (int i = startingIndex; i < arr.size(); ++i)
		{
			buckets[arr[i][pos]].push_back(std::move(arr[i]));
		}

		idx = startingIndex;
		for (auto& thisBucket : buckets)
		{
			for (std::string& s : thisBucket)
			{
				arr[idx++] = std::move(s);
			}

			thisBucket.clear();
		}
	}
}

int main()
{
	return 0;
}