#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) 
{
    int answer = 0;

    while (n >= a)
    {
        int Division = (n / a);
        int AddCoke = Division * b;
        answer += AddCoke;
        n = AddCoke + (n - Division);
    }
    
    return answer;
}