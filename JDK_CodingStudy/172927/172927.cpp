#include <string>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <queue>
using namespace std;

class MineralCost
{
public:
    MineralCost(int _Diamond = 0, int _Iron = 0, int _Stone = 0)
        : Diamond(_Diamond), Iron(_Iron), Stone(_Stone)
    {

    }

    // index로도 접근할 수 있게 union을 사용함.
    union
    {
        int Mineral[3];

        struct
        {
            int Diamond;
            int Iron;
            int Stone;
        };
    };


    void AddCost(int _MineralCost)
    {
        int DiaPickCost = static_cast<int>(pow(5, _MineralCost - 3));
        int IronPickCost = static_cast<int>(pow(5, _MineralCost - 2));
        int StonePickCost = static_cast<int>(pow(5, _MineralCost - 1));

        Diamond += DiaPickCost > 0 ? DiaPickCost : 1;
        Iron += IronPickCost > 0 ? IronPickCost : 1;
        Stone += StonePickCost > 0 ? StonePickCost : 1;
    }

    // priority_queue의 우선순위 때문에 만듦
    bool operator < (const MineralCost& _Value) const 
    {
        if (Stone == _Value.Stone)
        {
            if (Iron == _Value.Iron)
            {
                return Diamond > _Value.Diamond;
            }
            return Iron > _Value.Iron;
        }
        return Stone > _Value.Stone;
    }
};

int solution(vector<int> picks, vector<string> minerals) 
{
    unordered_map<string, int> CostOfMineral;
    CostOfMineral.insert({ "diamond", 3 });
    CostOfMineral.insert({ "iron", 2 });
    CostOfMineral.insert({ "stone", 1 });

    // 채굴 횟수 최댓값
    int NumOfMineral = static_cast<int>(minerals.size());
    int AllPickax = picks[0] + picks[1] + picks[2];
    int MaxNumToMine = NumOfMineral < (AllPickax * 5) ? NumOfMineral : (AllPickax * 5);


    // 광물을 5개씩 집합으로 나누어 각 곡괭이로 캘 때 필요한 피로도 계산 및 저장
    priority_queue<MineralCost> CostOfSets;
    int MaxSet = (MaxNumToMine / 5) * 5;
    for (int i = 0; i < MaxSet; i += 5)
    {
        MineralCost CurSetCost = MineralCost();
        for (int j = i; j < i + 5; ++j)
        {
            CurSetCost.AddCost(CostOfMineral[minerals[j]]);
        }

        CostOfSets.push(CurSetCost);
        CurSetCost = MineralCost();
    }

    // 5개씩 캐면 남는 광물이 존재할 수 있으므로 남은 광물까지 캠.
    if (MaxSet != MaxNumToMine)
    {
        MineralCost EndSetCost = MineralCost();
        for (int j = MaxSet; j < MaxNumToMine; ++j)
        {
            EndSetCost.AddCost(CostOfMineral[minerals[j]]);
        }

        CostOfSets.push(EndSetCost);
    }

    // 성능 좋은 곡괭이로 캐기위해 필요없는 곡괭이 버리기 
    MineralCost UsePickax = MineralCost();
    int SetSize = static_cast<int>(CostOfSets.size());
    for (int i = 0; i < 3; ++i)
    {
        if (picks[i] <= SetSize)
        {
            SetSize -= picks[i];
            UsePickax.Mineral[i] += picks[i];
        }
        else
        {
            UsePickax.Mineral[i] += SetSize;
            break;
        }
    }

    // 정렬된 집합을 효율이 낮은 순으로 피로도가 적게 사용되는 값을 구해 (이미 priority_queue로 정럴됨)
    // 피로도의 합을 구함.
    int answer = 0;
    for (int i = 2; i >= 0; --i)
    {
        while (UsePickax.Mineral[i] > 0)
        {
            answer += CostOfSets.top().Mineral[i];
            CostOfSets.pop();
            --UsePickax.Mineral[i];
        }
    }

    return answer;
}

int main()
{
    // 12
    int res1 = solution({ 1, 3, 2 }, 
        { "diamond", "diamond", "diamond", "iron", "iron", 
          "diamond", "iron", "stone" });

    // 50
    int res2 = solution({ 0, 1, 1 }, 
        { "diamond", "diamond", "diamond", "diamond", "diamond",
        "iron", "iron", "iron", "iron", "iron", 
        "diamond" });

    // 15
    int res3 = solution({ 1, 1, 1 },
        { "diamond", "diamond", "diamond", "diamond", "diamond",
        "iron", "iron", "iron", "iron", "iron",
        "stone", "stone", "stone", "stone", "stone",
        "iron", "iron", "iron", "iron", "iron",
		"diamond", "diamond", "diamond", "diamond", "diamond",
        "diamond", "diamond", "diamond", "diamond", "diamond", });
}