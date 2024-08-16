#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) 
{
    int answer = 0;
    int EndTileNumber = 0;

    // 빈 타일이 있으면 그리고 index m만큼 점프
    for(int i : section)
    {
        if (EndTileNumber < i)
        {
            EndTileNumber = i - 1 + m;
            answer++;
        }
    }

    return answer;
}

int main()
{
    int res = solution(8, 4, {2, 3, 6});
}