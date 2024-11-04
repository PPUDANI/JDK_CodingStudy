
#include <vector>
using namespace std;
int pageCount(int n, int p)
{
	int Front;
	int Back;

	if (p % 2 == 0)
	{
		Front = 0;
		Back = n % 2 == 0 ? n : n - 1;
	}
	else
	{
		Front = 1;
		Back = n % 2 == 0 ? n + 1 : n;
	}

	int FrontCount = abs(p - Front);
	int BackCount = abs(p - Back);

	if (FrontCount == 0 || BackCount == 0)
	{
		return 0;
	}

	return min(FrontCount, BackCount) / 2;
}


int main()
{
	int Res1 = pageCount(6, 2); // 1
	int Res2 = pageCount(5, 4); // 0

	int Res3 = pageCount(6, 5); // 1


}