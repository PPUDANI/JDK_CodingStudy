#include <string>
#include <vector>
#include <bitset>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) 
{
    vector<string> answer(n, "");

    // bitset을 사용하여 두 비트맵을 OR 연산해줌 
    for (int i = 0; i < n; ++i)
    {
        bitset<16> BitMap = arr1[i] | arr2[i];

        // '#'과 ' '로 치환하여 저장
        // 이진수와 문자열의 순서가 반대이므로 역순회
        for (int j = n - 1; j >= 0; --j)
        {
            char AddChar = BitMap[j] == true ? '#' : ' ';
            answer[i] += AddChar;
        }
    }

    return answer;
}




int main()
{
    solution(5, { 9, 20, 28, 18, 11 }, { 30, 1, 21, 17, 28 });
}