#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<bitset>

using namespace std;

int journeyToMoon(int n, vector<vector<int>> astronaut) 
{
	vector<vector<int>> Groups(n);

	for (vector<int> Pair : astronaut)
	{
		Groups[Pair[0]].push_back(Pair[1]);
		Groups[Pair[1]].push_back(Pair[0]);
	}

	int AstroCount = 0;
	vector<bool> AstroCheck(n, false);
	vector<int> GroupCounts(Groups.size(), 0);
	while (AstroCount < n)
	{
		queue<int> Q;
		for (int i = 0; i < n; ++i)
		{
			if (AstroCheck[i] == false)
			{
				++AstroCount;
				AstroCheck[i] = true;
				Q.push(0);
				break;
			}
		}

		int AstroCountToGroup = 1;
		while (!Q.empty())
		{
			int CurNode = Q.front();
			Q.pop();

			for (int NextNode : Groups[CurNode])
			{
				if (AstroCheck[NextNode] == false)
				{
					++AstroCountToGroup;
					AstroCheck[NextNode] = true;
					Q.push(NextNode);
				}
			}
		}

		GroupCounts.push_back(AstroCountToGroup);
		AstroCount += AstroCountToGroup;
	}

	int GroupNum = static_cast<int>(GroupCounts.size());
	int NumOfCombi = 0;
	
	for (int i = 0; i < GroupNum; ++i)
	{
		for (int j = i + 1; j < GroupNum; ++j)
		{
			NumOfCombi += GroupCounts[i] * GroupCounts[j];
		}
	}

	return NumOfCombi;
}

int main()
{
	int res = journeyToMoon(5, { {0, 1}, {2, 3}, {0, 4} }); 
	int res1 = journeyToMoon(4, { {0, 2} });


}