#include <string>
#include <vector>
#include <iostream>
using namespace std;

long long solution(int n)
{
    vector<int> Factorial(n + 1, 0);

    Factorial[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        Factorial[i] = (i * Factorial[i - 1]) % 1234567;
    }

    int NumOfOne = n;
    int NumOfTwo = 0;
    long long answer = 0;

    while (NumOfOne >= 0)
    {
        int AllNum = NumOfOne + NumOfTwo;

        int NumOfCombi = Factorial[AllNum] / (Factorial[NumOfOne] * Factorial[NumOfTwo]);
        answer += NumOfCombi % 1234567;

        NumOfOne -= 2;
        ++NumOfTwo;
    }

    return answer;
}

int main()
{
    int res1 = solution(4);
    int res2 = solution(5);

}