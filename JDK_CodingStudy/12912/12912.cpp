#include <string>
#include <vector>

using namespace std;
long long Sum(int a, int b)
{
    long long res = 0;
    long long Num = b - a + 1;
    long long sum = a + b;
    if (Num % 2 == 1)
    {
        --Num;
        res += sum / 2;
    }

    res += sum * (Num / 2);
    return res;
}

long long solution(int a, int b) 
{
    long long answer = 0;

    // 무조건 a가 작게 swap
    if (a > b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    if (a < 0)
    {
        // a, b 둘 다 음수일 경우
        if (b < 0)
        {
            answer -= Sum(abs(b), abs(a));
        }
        // a만 음수일 경우
        else
        {
            answer -= Sum(1, abs(a));
            answer += Sum(1, b);
        }
    }
    // a가 양수인 경우 a보다 큰 b도 양수임
    else
    {
        answer = Sum(a, b);
    }

    return answer;
}

int main()
{
    int res = solution(-2, -5); // -14
    int res2 = solution(-2, 5); // 12
    int res3 = solution(2, 5);  // 14
    int res4 = solution(0, 5);  // 15
}