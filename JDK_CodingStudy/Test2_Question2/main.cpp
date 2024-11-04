
#include <vector>
#include <algorithm>

using namespace std;

int lilysHomework(vector<int> arr)
{
	int ArrSize = static_cast<int>(arr.size());
	int ASCSwapCount = 0;
	for (int i = 0; i < ArrSize; ++i)
	{
		int MinIndex = i;
		for (int j = i + 1; j < ArrSize; ++j)
		{
			if (arr[MinIndex] > arr[j])
			{
				MinIndex = j;
			}
		}

		if (i != MinIndex)
		{
			++ASCSwapCount;
			swap(arr[i], arr[MinIndex]);
		}
	}
	int DESCSwapCount = 0;
	for (int i = 0; i < ArrSize; ++i)
	{
		int MaxIndex = i;
		for (int j = i + 1; j < ArrSize; ++j)
		{
			if (arr[MaxIndex] < arr[j])
			{
				MaxIndex = j;
			}
		}

		if (i != MaxIndex)
		{
			++DESCSwapCount;
			swap(arr[i], arr[MaxIndex]);
		}
	}


	return min(DESCSwapCount, ASCSwapCount);
}

int main()
{
	int res = lilysHomework(vector<int> arr)
	3 4 2 5 1
}