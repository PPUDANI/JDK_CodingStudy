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

    // ������ a�� �۰� swap
    if (a > b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    if (a < 0)
    {
        // a, b �� �� ������ ���
        if (b < 0)
        {
            answer -= Sum(abs(b), abs(a));
        }
        // a�� ������ ���
        else
        {
            answer -= Sum(1, abs(a));
            answer += Sum(1, b);
        }
    }
    // a�� ����� ��� a���� ū b�� �����
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