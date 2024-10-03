#include <vector>
#include <cmath>

using namespace std;

class int4
{
public:
    int4(int _Left = 0, int _Right = 0, int _Up = 0, int _Down = 0)
        :Left(_Left), Right(_Right), Up(_Up), Down(_Down) 
    {
    }

    union
    {
        int LRUD[4];
        struct
        {
            int Left;
            int Right;
            int Up;
            int Down;
        };
    };

    int4 operator +(const int4& _RValue) const
    {
        int4 Res;
        Res.Left = Left + _RValue.Left;
        Res.Right = Right + _RValue.Right;
        Res.Up = Up + _RValue.Up;
        Res.Down = Down + _RValue.Down;
        return Res;
    }
};

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls)
{
    vector<int> answer;

    // �� ���� ��ġ�� 4������ ��ǰ��� �Ÿ���
    int4 Start(startX, m - startX, n - startY, startY);
    for (vector<int> Ball : balls)
    {
        // Target�� ��ġ�� 4������ ��ǰ��� �Ÿ���
        int4 Target(Ball[0], m - Ball[0], n - Ball[1], Ball[1]);

        // Start�� Target�� �� ���� ��ģ�ٸ� �� �� ���� ���� üũ
        int ImmovableCushionDir = -1;
        if (startX == Ball[0])
        {
            ImmovableCushionDir = startY > Ball[1] ? 3 : 2;
        }
        else if(startY == Ball[1])
        {
            ImmovableCushionDir = startX > Ball[0] ? 0 : 1;
        }

        // �� �� ���� ������ ������ ������ ������ �Ÿ��� ���Ͽ� �ּҰ� ����
        int4 Sum = Start + Target;
        int MinDistance = 2147483647;
        for (int i = 0; i < 4; ++i)
        {
            if (i == ImmovableCushionDir)
            {
                continue;
            }
            
            int StartToTarget = 0;
			switch (i)
			{
			case 0: case 1:
				StartToTarget = abs(startY - Ball[1]);
				break;
			case 2: case 3:
				StartToTarget = abs(startX - Ball[0]);
				break;
			}

            int Result = pow(Sum.LRUD[i], 2) + pow(StartToTarget, 2);
            MinDistance = min(Result, MinDistance);
        }

        answer.push_back(MinDistance);
    }

    return answer;
}

int main()
{
    vector<int> Res = solution(10, 10, 3, 7, { { 7, 7 }, { 2, 7 }, { 7, 3 } });
    vector<int> Res2 = solution(10, 10, 5, 9, {{ 5, 8 }});
    vector<int> Res3 = solution(3, 3, 1, 1, { { 1, 2 } });
    vector<int> Res4 = solution(10, 10, 1, 1, { { 1, 9 } });
    vector<int> Res5 = solution(10, 10, 1, 9, { { 1, 8 } });
}

//vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls)
//{
//    vector<int> answer;
//    int4 Start(startX, m - startX, n - startY, startY);
//    
//    for (vector<int> Ball : balls)
//    {
//        int4 Target(Ball[0], m - Ball[0], n - Ball[1], Ball[1]);
//        int4 Sum = Start + Target;
//
//        int MinIndex = 0;
//        int MinOfSum = 0;
//
//        bool Same_X = Ball[0] == startX;
//        bool Same_Y = Ball[1] == startY;
//
//        for (int i = 0; i < 4; ++i)
//        {
//            if ()
//            {
//
//            }
//        }
//
//        int StartToTarget = 0;
//        switch (MinIndex)
//        {
//        case 0: case 1:
//            StartToTarget = abs(startY - Ball[1]);
//            break;
//
//        case 2: case 3:
//            StartToTarget = abs(startX - Ball[0]);
//            break;
//        }
//
//        int Result = pow(Sum.LRUD[MinIndex], 2) + pow(StartToTarget, 2);
//        answer.push_back(Result);
//    }
//
//    return answer;
//}