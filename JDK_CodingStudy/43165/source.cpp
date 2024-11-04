#include <vector>
#include <queue>

using namespace std;

int solution_BFS(vector<int> numbers, int target)
{
    int answer = 0;
    int ArrSize = int(numbers.size());

    //         idx  sum
    queue<pair<int, int>> BFS_Q;

    BFS_Q.push({ 0, numbers[0] });
    BFS_Q.push({ 0, -numbers[0] });

    while (!BFS_Q.empty())
    {
        int CurIndex = BFS_Q.front().first;
        int CurSum = BFS_Q.front().second;

        BFS_Q.pop();

        if (ArrSize == ++CurIndex)
        {
            if (CurSum == target)
            {
                ++answer;
                continue;
            }
        }
        else
        {
            BFS_Q.push({ CurIndex, CurSum + numbers[CurIndex] });
            BFS_Q.push({ CurIndex, CurSum - numbers[CurIndex] });
        }
    }

    return answer;
}

#include <stack>
int solution_DFS(vector<int> numbers, int target)
{
    int answer = 0;
    int ArrSize = int(numbers.size());

    stack<pair<int, int>, vector<pair<int, int>>> DFS_Stack;

    //            Index Stack
    DFS_Stack.push({ 0, numbers[0]});
    DFS_Stack.push({ 0, -numbers[0] });

    while (!DFS_Stack.empty())
    {
        int NextIndex = DFS_Stack.top().first + 1;
        int StackOfNum = DFS_Stack.top().second;
        DFS_Stack.pop();

        if (NextIndex == ArrSize)
        {
            if (StackOfNum == target)
            {
                ++answer;
            }
        }
        else
        {
            DFS_Stack.push({ NextIndex, StackOfNum + numbers[NextIndex] });
            DFS_Stack.push({ NextIndex, StackOfNum - numbers[NextIndex] });
        }
    }

    return answer;
}

int main()
{
    int res1 = solution_BFS({ 1, 1, 1, 1, 1 }, 3); // 5;
    int res2 = solution_BFS({ 4, 1, 2, 1 }, 4); // 2;

    int res3 = solution_DFS({ 1, 1, 1, 1, 1 }, 3); // 5;
    int res4 = solution_DFS({ 4, 1, 2, 1 }, 4); // 2;
}