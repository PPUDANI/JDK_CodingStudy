#include <string>
#include <vector>
#include <cmath>    
#include <algorithm>

#define EPSILON 0.00000000000001

bool compare(std::pair<float, int> Left, std::pair<float, int> Right)
{
    if (fabs(Left.first - Right.first) < EPSILON)
    {
        return Left.second < Right.second;
    }

    return Left.first > Right.first;
}

std::vector<int> solution(int N, std::vector<int> stages)
{
    // 스테이지별 클리어수 체크 
    std::vector<std::pair<float, int>> StageClearCounts; 

    for (int i = 1; i < N + 2; ++i)
    {
        StageClearCounts.push_back(std::make_pair(0.0f, i));
    }

    for (int i : stages)
    {
        ++StageClearCounts[i - 1].first;
    }

    // 스테이지별 실패율 연산
    int PlayerNumber = static_cast<int>(stages.size());
    std::transform(StageClearCounts.begin(), StageClearCounts.end(), StageClearCounts.begin(), [&](std::pair<float, int> i)
        {
            if (PlayerNumber <= 0)
            {
                i.first = 0;
                return i;
            }

            int Num =  static_cast<int>(i.first);
            i.first /= static_cast<float>(PlayerNumber);
            PlayerNumber -= Num;
            return i;
        });

    // 정렬
    std::sort(StageClearCounts.begin(), StageClearCounts.end() - 1, compare);

    // 정답 입력
    std::vector<int> answer;
    for (int i = 0; i < N; ++i)
    {
        answer.push_back(StageClearCounts[i].second);
    }

    return answer;
}

int main()
{
    std::vector<int> res = solution(5, { 2, 1, 2, 6, 2, 4, 3, 3 });
}
