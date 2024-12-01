#include <string>
#include <vector>

using namespace std;

#define EMPTY_BLOCK '.'

bool CheckMatch(char CheckIndex1, char CheckIndex2, char CheckIndex3, char CheckIndex4)
{
    bool IsAbleMatch = false;

    if (CheckIndex1 == CheckIndex2 &&
        CheckIndex2 == CheckIndex3 &&
        CheckIndex3 == CheckIndex4)
    {
        IsAbleMatch = true;
    }

    return IsAbleMatch;
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    // �⺻���� ������ �˻� �ٿ� 4��ġ�� �ȵǴ� ���� �˻翡�� �����ϱ�.
    // 4ĭ ���� 900ĭ ���� ������.

    int Loop_Height = m - 1;
    int Loop_Width = n - 1;


    bool IsAbleMatch = true;
    //int StartCheckLine = 0; // �˻縦 ������ ���� Index

    while (IsAbleMatch)
    {
        IsAbleMatch = false; // ��ü ��ġ ���� ���� üũ
        vector<vector<bool>> IsMatchBlock(m, vector<bool>(n, false)); // ��ġ�� ��� üũ

        for (int i = 0; i < Loop_Height; ++i)
        {
            //bool IsUnableMatchLine = true; // ���� ���� ��ġ ���� ���� üũ
            for (int j = 0; j < Loop_Width; ++j)
            {
                if (board[i][j] == EMPTY_BLOCK)
                {
                    continue;
                }

                if (CheckMatch(board[i][j], board[i + 1][j], board[i][j + 1], board[i + 1][j + 1]))
                {
                    IsMatchBlock[i][j] = true;
                    IsMatchBlock[i][j + 1] = true;
                    IsMatchBlock[i + 1][j] = true;
                    IsMatchBlock[i + 1][j + 1] = true;
                    IsAbleMatch = true;
                }
            }

            // �ش� ������ ��ġ
            //if(IsUnableMatchLine)
            //{
            //  ++StartCheckLine;
            //}
        }

        // ��ġ�� ��� ���� 
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (IsMatchBlock[i][j] == true)
                {
                    board[i][j] = EMPTY_BLOCK;
                    ++answer;
                }
            }
        }

        // ��������� ������
        for (int j = 0; j < n; ++j)
        {
            for (int i = m - 2; i >= 0; --i)
            {
                if (board[i][j] == EMPTY_BLOCK)
                {
                    continue;
                }

                int CheckHeight = i;
                bool IsAbleDown = false;
                while (CheckHeight < m - 1)
                {
                    if (board[CheckHeight + 1][j] == EMPTY_BLOCK)
                    {
                        IsAbleDown = true;
                        ++CheckHeight;
                    }
                    else
                    {
                        break;
                    }
                }

                if (IsAbleDown)
                {
                    board[CheckHeight][j] = board[i][j];
                    board[i][j] = EMPTY_BLOCK;
                }
            }
        }
    }

    return answer;
}

int main()
{
    int res1 = solution(4, 5, { "CCBDE", "AAADE", "AAABF", "CCBBF" }); // 14
    int res2 = solution(6, 6, { "TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ" }); // 15
    int a = 0;
}