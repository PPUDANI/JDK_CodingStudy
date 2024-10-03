#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// ��ͷ� �ѱ�� Parameter�� �ּ�ȭ �ϱ����� Class�� ������.
class Combination_Str
{
public:
    Combination_Str(const string& _Eliments, const int _CombiLength)
        : Eliments(_Eliments), CombiLength(_CombiLength)
    {
        // ���� �� ���ڿ��� ������������ ����
        sort(Eliments.begin(), Eliments.end(), [](const char _Left, const char _Right)
            {
                return _Left < _Right;
            });

        NumOfElement = static_cast<int>(Eliments.length());
    }

    //���� ���� �ߺ��� ������ ���� ����
    inline int GetNumOfMostCombi() const
    {
        return NumOfMostCombi;
    }
    
    void GetAllCombination(int _StartIndex, string _CurCombi, unordered_map<string, int>& _Combis)
    {
        int _DigitCount = CombiLength - 1;
        CalculateCombination(_StartIndex, _DigitCount, _CurCombi, _Combis);
    }

    // ��� �Լ�
    void CalculateCombination(int _StartIndex, int _DigitCount, string _CurCombi, unordered_map<string, int>& _Combis)
    {
        if (_CurCombi.length() == CombiLength)
        {
            int NumberOfCurStr = ++_Combis[_CurCombi];
            NumOfMostCombi = max(NumOfMostCombi, NumberOfCurStr);
            return;
        }

        if (_DigitCount > 0)
        {
            --_DigitCount;
        }

        for (int i = _StartIndex; i < NumOfElement - _DigitCount; ++i)
        {
            CalculateCombination(i + 1, _DigitCount, _CurCombi + Eliments[i], _Combis);
        }

        return;
    }

private:
    string Eliments;
    int NumOfElement;

    int CombiLength;
    int NumOfMostCombi = 0;
};


vector<string> solution(vector<string> orders, vector<int> course) 
{
    vector<string> answer;

    for (int CourseLength : course)
    {
        unordered_map<string, int> CourseMap;
        int NumOfMostCombi = 0;

        // ��� �ڽ� ����.
        for (const string& Order : orders)
        {
            Combination_Str CombiInst(Order, CourseLength);
            CombiInst.GetAllCombination(0, "", CourseMap);
            NumOfMostCombi = max(NumOfMostCombi, CombiInst.GetNumOfMostCombi());
        }

        // ���� ���� �ߺ��� ������ ������ 1�̶�� continue.
        if (NumOfMostCombi == 1)
        {
            continue;
        }

        // ���� ������ ������ ������ ��ġ�ϸ� ����
        for (const pair<string, int>& Course : CourseMap)
        {
            if (Course.second == NumOfMostCombi)
            {
                answer.push_back(Course.first);
            }
        }
    }

    // answer ����
    sort(answer.begin(), answer.end(), [](const string& _Left, const string& _Right)
        {
            return _Left < _Right;
        });

    return answer;
}

int main()
{
    vector<string> Res = solution({ "ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH" }, { 2, 3, 4 });
    //vector<string> Res = solution({ "XYZ", "XWY", "WXA" }, { 2, 3, 4 });
    int a = 0;
}
