#include <vector>
#include <iostream>

std::string solution(std::string X, std::string Y) {
    std::string answer = "";

    int XLength = static_cast<int>(X.length());
    int YLength = static_cast<int>(Y.length());

    // X, Y 서로 어떤 숫자를 몇 개 가지고 있는지 체크
    std::vector<int> XNum(10, 0);
    std::vector<int> YNum(10, 0);

    for (int i = 0; i < XLength; ++i)
    {
        int Num = static_cast<int>(X[i] - '0');
        ++XNum[Num];
    }

    for (int i = 0; i < YLength; ++i)
    {
        int Num = static_cast<int>(Y[i] - '0');
        ++YNum[Num];
    }


    for (int i = 9; i >= 0; --i)
    {
        // 가장 큰 수인 9부터 0까지 서로 숫자가 있는지 체크
        // 둘 다 가지고 있다면 결과값에 추가하고 개수를 한개씩 제거
        while (XNum[i] > 0 && YNum[i] > 0)
        {
            answer.push_back(i + '0');
            --XNum[i];
            --YNum[i];
        }
    }
#include <iostream>
#include <vector>

int solution(int number, int limit, int power) {
    int answer = 0;

    for (int CurNum = 1; CurNum <= number; ++CurNum) // 모든 기사 순회
    {
        // <소인수분해>
        // 24를 소인수분해 하면  2^3 * 3^1
        // 약수의 경우의 수를 구함
        
        //  X   | 2^0| 2^1| 2^2| 2^3
        // -----+----+----+----+-----
        //  3^0 |  1 |  2 |  4 |  8
        // -----+----+----+----+-----
        //  3^1 |  3 |  6 | 12 | 24
        
        // 약수의 개수는 8이 나옴.
        // 
        // 2^n * 3^m 이라고 했을 때
        // (n + 1)(m + 1) = 약수
        
        // 위와같은 소인수분해를 이용해 약수의 개수를 구하는 방법을 사용했음.

        int DivNum = CurNum; // 나눠지는 수
        int CurDiv = 2; // 나누는 수
        int DivCount = 0; // 나눠진 횟수(CurDiv의 지수 카운트)
        int Divisor = 1; // 약수 결과값

        while (1)
        {
            if (DivNum % CurDiv == 0) // 나머지가 0이라면 지수 카운트를 세고 DivNum을 나눔.
            {
                ++DivCount;
                DivNum /= CurDiv; // 나눠주면서 크기를 줄임.
            }
            else
            {
                if (DivCount != 0) // 더 이상 CurDiv로 나눠지지 않을 경우 연산 후 지수 초기화
                {
                    Divisor *= (1 + DivCount); // (지수 + 1)을 곱해주어 약수를 구함.
                    DivCount = 0;
                }

                if (CurDiv > DivNum) // CurDiv가 DivNum보다 큰 경우 더이상 나눌 수 없으므로 break
                {
                    break;
                }

                ++CurDiv;
            }
        }

        // Limit 검사
        if (Divisor > limit)
        {
            answer += power;
        }
        else
        {
            answer += Divisor;
        }
    }
    return answer;
}

int main()
{
    int res1 = solution(5, 3, 2);
    int res2 = solution(10, 3, 2);
}
    // 문제 예외처리
    if (answer.length() == 0)
    {
        return "-1";
    }
    else if (answer[0] == '0')
    {
        return "0";
    }

    return answer;
}

int main()
{
    std::string answer = solution("5525", "1255");
    std::cout << answer << std::endl;
}