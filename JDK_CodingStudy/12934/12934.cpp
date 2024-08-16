#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(long long n) 
{
   // ��Ʈ ������ ������ ���ϱ�
    double Root = sqrt(n);

    // ������ ������ �� ����
    long long IntegerRoot = static_cast<long long>(Root);

    // ���� ���� �������� �������� �Ǻ�
    if (Root - IntegerRoot > 0)
    {
        return -1;
    }
    else
    {
        ++IntegerRoot;
        return IntegerRoot * IntegerRoot;
    }
}

int main()
{
    long long res = solution(256);
}