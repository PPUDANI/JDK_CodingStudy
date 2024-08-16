#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(long long n) 
{
   // 루트 씌워서 제곱근 구하기
    double Root = sqrt(n);

    // 정수로 변경한 값 저장
    long long IntegerRoot = static_cast<long long>(Root);

    // 둘을 뺴서 제곱근이 정수인지 판별
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