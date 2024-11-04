
#include<vector>

using namespace std;


int beautifulPairs(vector<int> A, vector<int> B) 
{


}

int main()
{
	// A와 B에 있는 숫자중에 같은 숫자를 한 쌍으로 조합해야함.
	// 0 0  1 1  2 2  ->을 만들 수 있음
	// 근데 여기서 B의 숫자를 하나 바꿀 수 있음.
	// 0 0  1 1  2 2  3 3 -> 을 만들게 됨.
	// 이런식으로 B에 있는 숫자 하나를 바꿔서 만든 쌍의 최대 개수를 구해야함.

	int res = beautifulPairs({ 1, 2, 3, 4 }, {1, 2, 3, 3});
	int res2 = beautifulPairs({ 3, 5, 7, 11, 5, 8 }, { 5, 7, 11, 10, 5, 8 });
}
