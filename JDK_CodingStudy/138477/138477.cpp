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

        // Score�� �����ϸ� ����
        Jundang.insert(score[i]);

        // ���� �ڸ� ������ ������ ����
        if (CurSeat > k)
        {
            Jundang.erase(Jundang.begin());
            --CurSeat;
        }

        // ������ ����
        answer[i] = *(Jundang.begin());
    }

    return answer;
}