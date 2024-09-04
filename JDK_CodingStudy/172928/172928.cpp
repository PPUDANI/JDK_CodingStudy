#include <string>
#include <vector>

using namespace std;

// 좌표 및 방향을 저장할 클래스 생성
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
    // 공원 크기 체크
    int ParkHeight = static_cast<int>(park.size());
    int ParkWidth = static_cast<int>(park[0].length());

    // 시작 지점 찾기
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

    // 명령 수행
    int RoutesNumber = static_cast<int>(routes.size());
    for (int i = 0; i < RoutesNumber; ++i)
    {
        // 방향 체크
        Coordinate Direction;
        switch (routes[i][0])
        {
        case 'E': // 동
            Direction = { 1, 0 };
            break;

        case 'W': // 서
            Direction = { -1, 0 };
            break;

        case 'S': // 남
            Direction = { 0, 1 };
            break;

        case 'N': // 북
            Direction = { 0, -1 };
            break;

        default:
            Direction = { 0, 0 };
            break;
        }

        // 검사 기준 위치
        Coordinate MoveIndex = CurRobotIndex;

        // 이동 횟수
        int Distance = static_cast<int>(routes[i][2] - '0');

        // 이동 횟수 만큼 loop돌며 정해진 규칙을 통해 이동 가능 여부를 체크함.
        bool IsMovable = true;
        for (int j = 0; j < Distance; ++j)
        {
            MoveIndex += Direction;

            // Index 초과 여부 및 장애물 여부 확인
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

        // 이동이 가능하면 현재 위치를 움직인 위치로 초기화
        if (IsMovable == true)
        {
            CurRobotIndex = MoveIndex;
        }
    }

    // 결과 입력
    return { CurRobotIndex.Y, CurRobotIndex.X };
}

int main()
{
    vector<int> res = solution({ "OOO","SOO","OOO" }, { "E 2","S 2","W 1" });
}