#include <string>
#include <vector>

using namespace std;

// ��ǥ �� ������ ������ Ŭ���� ����
class Coordinate
{
public:
    Coordinate(int _X = 0, int _Y = 0) : X(_X), Y(_Y)
    { 

    }

    int X;
    int Y;

    Coordinate operator +=(const Coordinate Value)
    {
        Coordinate Res;
        X += Value.X;
        Y += Value.Y;
        return *(this);
    }

private:

};

vector<int> solution(vector<string> park, vector<string> routes) 
{
    // ���� ũ�� üũ
    int ParkHeight = static_cast<int>(park.size());
    int ParkWidth = static_cast<int>(park[0].length());

    // ���� ���� ã��
    Coordinate CurRobotIndex;
    for (int Y = 0; Y < ParkHeight; ++Y)
    {
        int X = static_cast<int>(park[Y].find('S'));
        if (X != string::npos)
        {
            CurRobotIndex = { X, Y };
            break;
        }
    }

    // ��� ����
    int RoutesNumber = static_cast<int>(routes.size());
    for (int i = 0; i < RoutesNumber; ++i)
    {
        // ���� üũ
        Coordinate Direction;
        switch (routes[i][0])
        {
        case 'E': // ��
            Direction = { 1, 0 };
            break;

        case 'W': // ��
            Direction = { -1, 0 };
            break;

        case 'S': // ��
            Direction = { 0, 1 };
            break;

        case 'N': // ��
            Direction = { 0, -1 };
            break;

        default:
            Direction = { 0, 0 };
            break;
        }

        // �˻� ���� ��ġ
        Coordinate MoveIndex = CurRobotIndex;

        // �̵� Ƚ��
        int Distance = static_cast<int>(routes[i][2] - '0');

        // �̵� Ƚ�� ��ŭ loop���� ������ ��Ģ�� ���� �̵� ���� ���θ� üũ��.
        bool IsMovable = true;
        for (int j = 0; j < Distance; ++j)
        {
            MoveIndex += Direction;

            // Index �ʰ� ���� �� ��ֹ� ���� Ȯ��
            if (0 > MoveIndex.Y ||
                0 > MoveIndex.X ||
                ParkHeight <= MoveIndex.Y ||
                ParkWidth <= MoveIndex.X ||
                park[MoveIndex.Y][MoveIndex.X] == 'X')
            {
                IsMovable = false;
                break;
            }
        }

        // �̵��� �����ϸ� ���� ��ġ�� ������ ��ġ�� �ʱ�ȭ
        if (IsMovable == true)
        {
            CurRobotIndex = MoveIndex;
        }
    }

    // ��� �Է�
    return { CurRobotIndex.Y, CurRobotIndex.X };
}

int main()
{
    vector<int> res = solution({ "OOO","SOO","OOO" }, { "E 2","S 2","W 1" });
}