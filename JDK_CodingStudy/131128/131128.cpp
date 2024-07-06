#include <vector>
#include <iostream>

std::string solution(std::string X, std::string Y) {
    std::string answer = "";

    int XLength = static_cast<int>(X.length());
    int YLength = static_cast<int>(Y.length());

    // X, Y ���� � ���ڸ� �� �� ������ �ִ��� üũ
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
        // ���� ū ���� 9���� 0���� ���� ���ڰ� �ִ��� üũ
        // �� �� ������ �ִٸ� ������� �߰��ϰ� ������ �Ѱ��� ����
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

    for (int CurNum = 1; CurNum <= number; ++CurNum) // ��� ��� ��ȸ
    {
        // <���μ�����>
        // 24�� ���μ����� �ϸ�  2^3 * 3^1
        // ����� ����� ���� ����
        
        //  X   | 2^0| 2^1| 2^2| 2^3
        // -----+----+----+----+-----
        //  3^0 |  1 |  2 |  4 |  8
        // -----+----+----+----+-----
        //  3^1 |  3 |  6 | 12 | 24
        
        // ����� ������ 8�� ����.
        // 
        // 2^n * 3^m �̶�� ���� ��
        // (n + 1)(m + 1) = ���
        
        // ���Ͱ��� ���μ����ظ� �̿��� ����� ������ ���ϴ� ����� �������.

        int DivNum = CurNum; // �������� ��
        int CurDiv = 2; // ������ ��
        int DivCount = 0; // ������ Ƚ��(CurDiv�� ���� ī��Ʈ)
        int Divisor = 1; // ��� �����

        while (1)
        {
            if (DivNum % CurDiv == 0) // �������� 0�̶�� ���� ī��Ʈ�� ���� DivNum�� ����.
            {
                ++DivCount;
                DivNum /= CurDiv; // �����ָ鼭 ũ�⸦ ����.
            }
            else
            {
                if (DivCount != 0) // �� �̻� CurDiv�� �������� ���� ��� ���� �� ���� �ʱ�ȭ
                {
                    Divisor *= (1 + DivCount); // (���� + 1)�� �����־� ����� ����.
                    DivCount = 0;
                }

                if (CurDiv > DivNum) // CurDiv�� DivNum���� ū ��� ���̻� ���� �� �����Ƿ� break
                {
                    break;
                }

                ++CurDiv;
            }
        }

        // Limit �˻�
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
    // ���� ����ó��
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