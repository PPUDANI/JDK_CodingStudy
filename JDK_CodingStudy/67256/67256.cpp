#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

enum class EHAND
{
    LEFT = 0,
    RIGHT,
    NONE
};

// 벡터 구하듯이 계산하려다 매번 계산하는게 불편해서 메모리 씀
// 'Center'값 부터 'Index'까지의 거리 저장
static std::unordered_map<int, std::vector<int>> DistanceFromCenter =
{   
    //     0  1  2  3  4  5  6  7  8  9  *  #
    { 0, { 0, 4, 3, 4, 3, 2, 3, 2, 1, 2, 1, 1 } },
    { 2, { 3, 1, 0, 1, 2, 1, 2, 3, 2, 3, 4, 4 } },
    { 5, { 2, 2, 1, 2, 1, 0, 1, 2, 1, 2, 3, 3 } },
    { 8, { 1, 3, 2, 3, 2, 1 ,2, 1, 0, 1, 2, 2 } }
};

string solution(vector<int> numbers, string hand) 
{
    string answer = "";

    EHAND HandCheck = hand[0] == 'r' ? EHAND::RIGHT : EHAND::LEFT;
    EHAND CurMovedHand = EHAND::NONE;

    int CurLeftHandLocation = 10; // => '*' Index
    int CurRightHandLocation = 11; // => '#' Index

    int DistanceOfLeft = 0;
    int DistanceOfRight = 0;

    for (int Num : numbers)
    {
        // Num을 받아 왼손 오른손 체크
        switch (Num)
        {
        case 1: case 4: case 7:
            CurMovedHand = EHAND::LEFT;
            break;

        case 3: case 6: case 9:
            CurMovedHand = EHAND::RIGHT;
            break;

        case 2: case 5: case 8: case 0:
            DistanceOfLeft = DistanceFromCenter[Num][CurLeftHandLocation];
            DistanceOfRight = DistanceFromCenter[Num][CurRightHandLocation];

            if (DistanceOfLeft == DistanceOfRight)
            {
                CurMovedHand = HandCheck;
            }
            else
            {
                CurMovedHand = DistanceOfLeft > DistanceOfRight ? EHAND::RIGHT : EHAND::LEFT;
            }
			break;

        default:
            break;
        }

        // 현재 움직인 손의 위치 저장 및 반환값에 추가
        switch (CurMovedHand)
        {
        case EHAND::LEFT:
            CurLeftHandLocation = Num;
            answer += 'L';
            break;
        case EHAND::RIGHT:
            CurRightHandLocation = Num;
            answer += 'R';
            break;
        default:
            break;
        }
    }

    return answer;
}
