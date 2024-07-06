#include <string>

#include <vector>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";

    int sNum = static_cast<int>(s.length());
    int skipNum = static_cast<int>(skip.length());

    // 모든 Alphabet을 따로 적재
    char Alphabet[26] = { 0, };

    // skip에 있는 Alphabet값을 -1로 수정 
    for (int i = 0; i < skipNum; ++i)
    {
        --Alphabet[skip[i] - 'z'];
    }

    for (int i = 0; i < sNum; ++i)
    {
        int CurIndex = s[i] - 'z';
        int Count = index;
        while (Count)
        {
            ++CurIndex;

            if (CurIndex > 25)
            {
                CurIndex -= 26;
            }

            if (Alphabet[CurIndex] != -1)
            {
                --Count;
            }
        }

        answer.push_back(static_cast<char>(CurIndex + 'z'));
    }

    return answer;
}

int main()
{
    std::string res1 = solution("z", "a", 1); // "b"
    std::string res2 = solution("a", "bcdefghijk", 20); // "o"
    std::string res3 = solution("z", "abcdefghij", 20); // "n"
    std::string res4 = solution("aukks", "wbqd", 5); // "happy"
    std::string res5 = solution("abcde", "bcd", 2); // "ffffg"


    std::string res6 = solution("yyyyy", "za", 2); // "ccccc"
    std::string res7 = solution("ybcde", "az", 1); // "bcdef"
    std::string res8 = solution("zzzzzz", "abcdefghijklmnopqrstuvwxy", 6); // "zzzzzz"
    std::string res9 = solution("bcdefghijklmnopqrstuvwxyz", "a", 1); // "cdefghijklmnopqrstuvwxyzb"
}
