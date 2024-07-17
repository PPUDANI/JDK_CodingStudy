#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";

    int SooBackNum = n / 2;

    for (int i = 0; i < SooBackNum; ++i)
    {
        answer += "¼ö¹Ú";
    }

    if (n % 2 == 1)
    {
        answer += "¼ö";
    }

    return answer;
}

int main()
{
    string res = solution(9);
}