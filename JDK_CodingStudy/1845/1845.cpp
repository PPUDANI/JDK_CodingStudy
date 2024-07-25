#include <vector>
#include <unordered_set>
using namespace std;

int solution(vector<int> nums)
{
    // 중복이 없고 정렬하지 않는 unordered_set을 사용
    std::unordered_set<int> Ponketmons(nums.begin(), nums.end());
    
    // 폰켓몬을 가져갈 수 있는 최대 개수 N/2
    int MaxNumberOfPick = static_cast<int>(nums.size()) / 2;

    // 폰켓몬 종류의 개수
    int NumberOfPonketmon = static_cast<int>(Ponketmons.size());

    // 폰켓몬 종류가 가져갈 수 있는 최대 개수보다 많으면 최대개수 리턴
    // 최대 선택 개수가 폰켓몬 종류보다 많으면 폰켓몬 종류 리턴
    return MaxNumberOfPick < NumberOfPonketmon ? MaxNumberOfPick : NumberOfPonketmon;
}   