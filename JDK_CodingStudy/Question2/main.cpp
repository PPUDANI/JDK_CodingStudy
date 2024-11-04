#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define MAX_COST INT32_MAX

void getCost(int g_nodes, vector<int> g_from, vector<int> g_to, vector<int> g_weight) 
{
    vector<vector<pair<int, int>>> Graph(g_nodes + 1);

    for (int i = 0; i < g_from.size(); ++i) 
    {
        Graph[g_from[i]].push_back({ g_to[i], g_weight[i] });
        Graph[g_to[i]].push_back({ g_from[i], g_weight[i] });
    }

    vector<int> Cost(g_nodes + 1, MAX_COST);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Dijkstra_PQ;

    Cost[1] = 0;
    Dijkstra_PQ.push({ 1, 0 });

    while (!Dijkstra_PQ.empty())
    {
        int CurNode = Dijkstra_PQ.top().first;
        int CurCost = Dijkstra_PQ.top().second;
        Dijkstra_PQ.pop();

        if (CurNode == g_nodes)
        {
            cout << CurCost;
            return;
        }

        for (pair<int, int> NextNode : Graph[CurNode])
        {
            int MaxCost = max(CurCost, NextNode.second);
            if (MaxCost < Cost[NextNode.first])
            {
                Cost[NextNode.first] = MaxCost;
                Dijkstra_PQ.push({ NextNode.first , MaxCost });
            }
        }
    }

    cout << "NO PATH EXISTS";
    return;
}

int main()
{
	getCost(5, { 1, 3, 1, 4, 2 }, { 2, 5, 4, 5, 3 }, { 60, 70, 120, 150, 80 }); // 80
	getCost(5, { 1, 2, 3, 4, 1, 3 }, { 2, 3, 4, 5, 3, 5 }, { 30, 50, 70, 90, 70, 85}); // 85

}
