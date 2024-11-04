#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int surfaceArea(vector<vector<int>> A) 
{
	int XSize = static_cast<int>(A.size());
	int YSize = static_cast<int>(A[0].size());

	int XPrise = 0;
	for (int i = 0; i < XSize; ++i)
	{
		int CurDif = 0;
		for (int j = 0; j < YSize; ++j)
		{
			XPrise += abs(CurDif - A[i][j]);
			CurDif = A[i][j];
		}
		XPrise += CurDif;
	}

	int YPrise = 0;
	
	for (int i = 0; i < YSize; ++i)
	{
		int CurDif = 0;
		for (int j = 0; j < XSize; ++j)
		{
			YPrise += abs(CurDif - A[j][i]);
			CurDif = A[j][i];
		}
		YPrise += CurDif;
	}

	int ZPrise = XSize * YSize * 2;
	int TotalPrise = XPrise + YPrise + ZPrise;

	return TotalPrise;
}

int main()
{
	// 6면 검사해서 면 개수가 가격임 근데 가려져도 측면으로 보이면 추가해야함.
	int res = surfaceArea({ {1} });
	int res1 = 
		surfaceArea(
			{ {1, 3, 4},
		      {2, 2, 3},
			  {1, 2, 4} });

}
