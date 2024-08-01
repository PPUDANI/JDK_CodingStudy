#include <string>
#include <vector>

using namespace std;

int solution(string s)
{
    int answer = 0;
    int StringSize = static_cast<int>(s.size());


    std::string Result = "";
    for (int i = 0; i < StringSize; ++i)
    {
        if (s[i] <= '9')
        {
            Result += s[i];
            continue;
        }

        switch (s[i])
        {
        case 'z':
            Result += '0';
            i += 3;
            break;

        case 'o':
            Result += '1';
            i += 2;
            break;

        case 't':
            if (s[i + 1] == 'w')
            {
                Result += '2';
                i += 2;
            }
            else
            {
                Result += '3';
                i += 4;
            }
            break;

        case 'f':
            if (s[i + 1] == 'o')
            {
                Result += '4';
                i += 3;
            }
            else
            {
                Result += '5';
                i += 3;
            }
            break;

        case 's':
            if (s[i + 1] == 'i')
            {
                Result += '6';
                i += 2;
            }
            else
            {
                Result += '7';
                i += 4;
            }
            break;

        case 'e':
            Result += '8';
            i += 4;
            break;

        case 'n':
            Result += '9';
            i += 3;
            break;

        default:
            break;
        }
    }
    answer = stoi(Result);
    return answer;
}

/************************************************************
#include <regex>
using namespace std;

int solution(string s) 
{
    s = regex_replace(s, regex("zero"), "0");
    s = regex_replace(s, regex("one"), "1");
    s = regex_replace(s, regex("two"), "2");
    s = regex_replace(s, regex("three"), "3");
    s = regex_replace(s, regex("four"), "4");
    s = regex_replace(s, regex("five"), "5");
    s = regex_replace(s, regex("six"), "6");
    s = regex_replace(s, regex("seven"), "7");
    s = regex_replace(s, regex("eight"), "8");
    s = regex_replace(s, regex("nine"), "9");
    return stoi(s);
}
*************************************************************/


int main()
{
    int res = solution("one4seveneight");
}