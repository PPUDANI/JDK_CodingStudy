#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    std::stack<int> Basket;
    Basket.push(-1);

    int Height = board.size(); // N * N size
    for (int i : moves)
    {
        --i; // move값 index 맞추기
        for (int j = 0; j < Height; ++j)
        {
            if (board[j][i] == 0)
            {
                continue;
            }
            else
            {
                int a = Basket.top();
                int b = board[j][i];
                if (a == b)
                {
                    Basket.pop();
                    answer += 2;
                }
                else
                {
                    Basket.push(board[j][i]);
                }
                board[j][i] = 0;
                break;
            }
        }
    }
    return answer;
}

int main()
{
    int a = solution
    (
        {
            {0, 0, 0, 0, 0},
            {0, 0, 1, 0, 3},
            {0, 2, 5, 0, 1},
            {4, 2, 4, 4, 2},
            {3, 5, 1, 3, 1}
        },
        { 1, 5, 3, 5, 1, 2, 1, 4 }
    );
}