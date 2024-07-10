#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

std::vector<std::string> solution(std::vector<std::string> players, std::vector<std::string> callings)
{
    int PlayerNum = players.size();
    int CallingNum = callings.size();

    std::vector<int> CurRank(PlayerNum);
    std::unordered_map<std::string, int> PlayerHash;
    std::vector<std::string> answer(PlayerNum);

    for (int i = 0; i < PlayerNum; ++i)
    {
        CurRank[i] = i;
        PlayerHash.insert({ players[i], i });
    }

    for (std::string i : callings)
    {
        int Key = PlayerHash[i]; // hash로 선수의 key 참조

        for (int i = 0; i < PlayerNum; ++i)
        {
            if (CurRank[i] == Key)
            {
                int temp = CurRank[i];
                CurRank[i] = CurRank[i - 1];
                CurRank[i - 1] = temp;
                break;
            }
        }
    }

    for (int i = 0; i < PlayerNum; ++i)
    {
        answer[i] = players[CurRank[i]];
    }

    return answer;
}
