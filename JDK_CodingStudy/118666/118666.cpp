#include <string>
#include <vector>

using namespace std;

class CACAO_MBTI
{
public:
    CACAO_MBTI() {}

    static bool CheckTypeSequence_Left(char _Left)
    {
        if (_Left == 'R' || _Left == 'C' || _Left == 'J' || _Left == 'A')
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    string GetMBTI()
    {
        string Res = "";
        Res += GetDominantType(RT, 'R', 'T');
        Res += GetDominantType(CF, 'C', 'F');
        Res += GetDominantType(JM, 'J', 'M');
        Res += GetDominantType(AN, 'A', 'N');
        return Res;
    }

    void AddScore(char _Left, int _Score)
    {
        switch (_Left)
        {
        case 'R': 
        case 'T':
            RT += _Score;
            break;

        case 'C': 
        case 'F':
            CF += _Score;
            break;

        case 'J': 
        case 'M':
            JM += _Score;
            break;

        case 'A': 
        case 'N':
            AN += _Score;
            break;

        default:
            break;
        }
    }

private:
    int RT = 0;
    int CF = 0;
    int JM = 0;
    int AN = 0;

    char GetDominantType(float Score, char _Left, char _Right)
    {
        if (Score <= 0)
        {
            return _Left;
        }
        else
        {
            return _Right;
        }
    }
};

string solution(vector<string> survey, vector<int> choices) 
{
    // MBTI Class를 만듦.
    CACAO_MBTI Result;

    int QnANum = static_cast<int>(survey.size());

    // 검사 자료 접근.
    for (int i = 0; i < QnANum; ++i)
    {
        // 대칭인 점수를 만들기 위해 -4를 해줌.

        // -3 | -2 | -1 |  0 |  1 |  2 |  3
        int Score = choices[i] - 4; 

        // 해당 문제 점수 지표가 CACAO_MBTI Class의 성격 순서와 반대일 경우 -1을 곱해줌.
        // 대칭으로 만든 이유임.
        // 예) "RT"가 아닌 "TR"일 경우
        if (CACAO_MBTI::CheckTypeSequence_Left(survey[i][0]) == false)
        {
            Score *= -1;
        }
        // 점수를 더해줌
        Result.AddScore(survey[i][0], Score);
    }

    // GetMBTI()에서 성격 유형별 점수들을 통해 MBTI를 제공해줌.
    return Result.GetMBTI();
}


int main()
{
    solution({ "AN", "CF", "MJ", "RT", "NA" }, { 5, 3, 2, 7, 5 });
}