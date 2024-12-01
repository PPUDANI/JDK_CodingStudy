#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 99999999;
vector<int> solution(string s)
{
    vector<int> answer;

    // 제일 원소의 개수가 적은 튜플을 기준으로 해야함.
    vector<vector<char>> Tuples;

    int Length = int(s.length()) - 1;
    int idx = 1;

    int TubleIndex = 0;
    while (idx < Length)
    {
        if (s[idx] == '{')
        {
            while (s[idx] != '}')
            {
                if (s[idx] != ',')
                {
                    Tuples[TubleIndex].push_back(s[idx]);
                }
                ++idx;

                if (idx == Length) // 문제있는 문자열임.
                {
                    return vector<int>();
                }
            }

            ++TubleIndex;
        }
        else
        {
            ++idx;
        }
    }

    sort(Tuples.begin(), Tuples.end(), [](const vector<char>& Left, const vector<char>& Right) -> bool
        {
            return Left.size() < Right.size();
        });


    int NumOfTuple = int(Tuples.size());
    for (int i = 0; i < NumOfTuple; ++i)
    {
        for (char c : Tuples[i])
        {

            answer.push_back(c - '0');
        }
    }


    return answer;
}