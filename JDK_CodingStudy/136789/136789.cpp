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