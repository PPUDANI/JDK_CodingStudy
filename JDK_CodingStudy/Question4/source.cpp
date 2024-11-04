#include<iostream>
#include<vector>
#include<queue>
using namespace std;
// a = 원소개수
// k = 회전수
// queries = 검색 index

vector<int> circularArrayRotation(vector<int> a, int k, vector<int> queries)
{
    int NumOfElement = static_cast<int>(a.size());

    vector<int> Result;
    int NumOfQuery = static_cast<int>(queries.size());

    for (int i = 0; i < NumOfQuery; ++i)
    {
        int Index = (queries[i] + k) % NumOfElement;
        Result.push_back(a[Index]);
    }

    return Result;
}


int main()
{
	// 2 3 1 -> 2 3 1
	vector<int> res = circularArrayRotation({ 1, 2, 3 }, 2, { 0, 1, 2 }); // 2 3 1

	// 3 4 1 2 -> 3 4 1
	vector<int> res1 = circularArrayRotation({ 1, 2, 3, 4}, 2, { 0, 1, 2 }); // 3 4 1

	// 4 5 6 7 8 1 2 3
	vector<int> res2 = circularArrayRotation({ 1, 2, 3, 4, 5, 6, 7, 8 }, 5, { 0, 1, 2, 3 }); // 4 5 6 7
}