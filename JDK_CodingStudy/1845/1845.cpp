#include <vector>
#include <unordered_set>
using namespace std;

int solution(vector<int> nums)
{
    // �ߺ��� ���� �������� �ʴ� unordered_set�� ���
    std::unordered_set<int> Ponketmons(nums.begin(), nums.end());
    
    // ���ϸ��� ������ �� �ִ� �ִ� ���� N/2
    int MaxNumberOfPick = static_cast<int>(nums.size()) / 2;

    // ���ϸ� ������ ����
    int NumberOfPonketmon = static_cast<int>(Ponketmons.size());

    // ���ϸ� ������ ������ �� �ִ� �ִ� �������� ������ �ִ밳�� ����
    // �ִ� ���� ������ ���ϸ� �������� ������ ���ϸ� ���� ����
    return MaxNumberOfPick < NumberOfPonketmon ? MaxNumberOfPick : NumberOfPonketmon;
}   