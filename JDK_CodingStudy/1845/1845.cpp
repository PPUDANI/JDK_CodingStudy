#include <vector>
#include <unordered_set>
using namespace std;

int solution(vector<int> nums)
{
    // �ߺ��� ���� �������� �ʴ� unordered_set�� ���
    std::unordered_set<int> Ponketmons(nums.begin(), nums.end());
    
    int MaxNumberOfPick = static_cast<int>(nums.size()) / 2;
    int NumberOfPonketmon = static_cast<int>(Ponketmons.size());

    return MaxNumberOfPick < NumberOfPonketmon ? MaxNumberOfPick : NumberOfPonketmon;
}   