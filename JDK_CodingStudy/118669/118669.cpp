#include <string>
#include <vector>
#include <queue>

using namespace std;

#define INF 99999999

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits)
{
    vector<vector<pair<int, int>>> Graph(n + 1);

    for (vector<int> Path : paths)
    {
        int From = Path[0];
        int To = Path[1];
        int Rest = Path[2];

        Graph[From].push_back({ Rest, To });
    }

    vector<int> MinRestToNode(n + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;

    vector<bool> GateCheck(n + 1, false);
    for (int GateNode : gates)
    {
        GateCheck[GateNode] = true;
        PQ.push({ 0, GateNode });
    }

    vector<bool> SummitCheck(n + 1, false);
    for (int SummitNode : summits)
    {
        SummitCheck[SummitNode] = true;
    }

    while (!PQ.empty())
    {
        int CurNode = PQ.top().second;
        int CurRest = PQ.top().first;
        PQ.pop();

        if (SummitCheck[CurNode] == true)
        {
            continue;
        }

        if (MinRestToNode[CurNode] < CurRest)
        {
            continue;
        }

        for (pair<int, int> Next : Graph[CurNode])
        {
            int NextNode = Next.second;
            if (GateCheck[NextNode] == true)
            {
                continue;
            }

            int NewRest = max(CurRest, Next.first);
            if (MinRestToNode[NextNode] > NewRest)
            {
                MinRestToNode[NextNode] = NewRest;
                PQ.push({ NewRest, NextNode });
            }
        }
    }

    vector<int> answer = { INF, INF };
    for (int Summit : summits)
    {
        if (MinRestToNode[Summit] < answer[1])
        {
            answer[1] = MinRestToNode[Summit];
            answer[0] = Summit;
        }
        else if (MinRestToNode[Summit] == answer[1])
        {
            answer[0] = min(answer[0], Summit);
        }
    }

    return answer;
}
int main()
{
    vector<int> res1 = solution(7,
    { { 1, 4, 4 },
    { 1, 6, 1 },
    { 1, 7, 3 },
    { 2, 5, 2 },
    { 3, 7, 4 },
    { 5, 6, 6 }
        }, { 1 }, {2, 3, 4});

    vector<int> res2 = solution(7,
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