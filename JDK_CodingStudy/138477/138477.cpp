#include <string>
#include <set>
#include <vector>

std::vector<int> solution(int k, std::vector<int> score) 
{
    
    int Day = static_cast<int>(score.size());

    std::vector<int> answer(Day);

  
    std::multiset<int> Jundang;

    int CurSeat = 0;
    for (int i = 0; i < Day; ++i)
    {
        ++CurSeat;

        // Score를 삽입하며 정렬
        Jundang.insert(score[i]);

        // 전당 자리 꽉차면 최하위 제명
        if (CurSeat > k)
        {
            Jundang.erase(Jundang.begin());
            --CurSeat;
        }

        // 최하위 삽입
        answer[i] = *(Jundang.begin());
    }

    return answer;
}