#include <string>
#include <vector>
#include <queue>

using namespace std;

#define NODE_MAX 99999
#define COST_MAX 9999999
vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits)
{
    int NumOfSummit = int(summits.size());
    vector<vector<pair<int, int>>> Graph(n + 1);
    for (vector<int> path : paths)
    {
        int NodeA = path[0];
        int NodeB = path[1];
        int Cost = path[2];

        Graph[NodeA].push_back({ Cost, NodeB });
        Graph[NodeB].push_back({ Cost, NodeA });
    }

    //                  Cost Node
    priority_queue<pair<int, int>> PQ;
    vector<int> CostToNode(n + 1);

    for (int GateNode : gates)
    {
        PQ.push({ 0, GateNode });
        CostToNode[GateNode] = 0;
    }

    while (!PQ.empty())
    {
        int CurNode = PQ.top().first;
        int CurCost = PQ.top().second;

        PQ.pop();

        bool IsSummit = false;
        for (int i = 0; i < NumOfSummit; ++i)
        {
            if (summits[i] == CurNode)
            {
                if (CostToNode[CurNode] > CurCost)
                {
                    IsSummit = true;
                    CostToNode[CurNode] = CurCost;
                    break;
                }
            }
        }

        if (IsSummit == true)
        {
            continue;
        }

        for (pair<int, int> Edge : Graph[CurNode])
        {
            int NextNode = Edge.first;
            int NextCost = Edge.second;

            bool IsGate = false;
            for (int GateNode : gates)
            {
                if (NextNode == GateNode)
                {
                    IsGate = true;
                    break;
                }
            }

            if (IsGate == false)
            {
                int MaxCost = max(CurCost, NextCost);
                if (CostToNode[NextCost] > MaxCost)
                {
                    CostToNode[NextCost] = MaxCost;
                    PQ.push({ MaxCost, NextNode });
                }
            }
        }
    }

    vector<int> answer = { NODE_MAX, COST_MAX };

    for (int SummitNode : summits)
    {
        if (answer[1] > CostToNode[SummitNode])
        {
            answer[1] = CostToNode[SummitNode];
            answer[0] = CostToNode[SummitNode];
        }
        else if (answer[1] == CostToNode[SummitNode])
        {
            answer[0] = min(answer[0], SummitNode);
        }
    }

    return answer;
}


int main()
{
    vector<int> res = solution(7,
        { {1, 2, 5},
        {1, 4, 1},
        { 2, 3, 1 },
        {2, 6, 7},
        {4, 5, 1},
        {5, 6, 1},
        {6, 7, 1} },
        { 3, 7 },
        { 1, 5 });
}