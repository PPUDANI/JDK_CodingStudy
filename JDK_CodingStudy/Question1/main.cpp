
#include<vector>

using namespace std;


int beautifulPairs(vector<int> A, vector<int> B) 
{


}

int main()
{
	// A�� B�� �ִ� �����߿� ���� ���ڸ� �� ������ �����ؾ���.
	// 0 0  1 1  2 2  ->�� ���� �� ����
	// �ٵ� ���⼭ B�� ���ڸ� �ϳ� �ٲ� �� ����.
	// 0 0  1 1  2 2  3 3 -> �� ����� ��.
	// �̷������� B�� �ִ� ���� �ϳ��� �ٲ㼭 ���� ���� �ִ� ������ ���ؾ���.

	int res = beautifulPairs({ 1, 2, 3, 4 }, {1, 2, 3, 3});
	int res2 = beautifulPairs({ 3, 5, 7, 11, 5, 8 }, { 5, 7, 11, 10, 5, 8 });
}
