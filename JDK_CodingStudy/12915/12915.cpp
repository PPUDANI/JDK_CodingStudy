#include <string>
#include <vector>
#include <algorithm>
using namespace std;


vector<string> solution(vector<string> c, int n) 
{
    // Index n을 기준으로 정렬
    std::sort(c.begin(), c.end(), [&](const string& Left, const string& Right)
        {
            if (Left[n] == Right[n])
            {
                return Left < Right;
            }
            return Left[n] < Right[n];
        });

    return c;
}



int main()
{
    solution({ "abce", "abcd", "cdx" }, 2);
}