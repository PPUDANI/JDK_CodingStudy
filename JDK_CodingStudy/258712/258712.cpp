#include <string>
#include <sstream>

#include <vector>
#include <unordered_map>
#include <unordered_set>

#include <algorithm>

using namespace std;

// �� ����鸶�� ������ �� ������ ��� Ŭ����
class GiftInfo
{
public:
    GiftInfo()
    {

    }

    // �ֱ�
    void GiveGift(const string& _Name)
    {
        GiveFriends.insert(_Name);
    }

    // �ޱ�
    void ReceiveGift(const string& _Name)
    {
        ++NumOfReceived;
    }

    // Ư�� ģ������ ������ �� Ƚ��
    int GetCountOfGaveToFriend(const string& _Name)
    {
        int Count = static_cast<int>(GiveFriends.count(_Name));
        return Count;
    }

    // ���� ���� ��ȯ
    int GetGiftPoint()
    {
        int Point = static_cast<int>(GiveFriends.size() - NumOfReceived);
        return Point;
    }

private:
    // ������ ���� Ƚ���� ������ ���� Give�� multiset ���.
    unordered_multiset<string> GiveFriends;
    int NumOfReceived;
};


int solution(vector<string> friends, vector<string> gifts) 
{
    int FriendNum = static_cast<int>(friends.size());

    // ������� �̸��� ������ ���� Map ����
    unordered_map<string, GiftInfo> FriendMap;

    // FriendMap �ʱ�ȭ �� ��ü ����
    for (const string& str : friends)
    {
        FriendMap[str] = GiftInfo();
    }

    // gift�� �����ͷ� ��� ���� ������ �ְ���� Ƚ�� ���
    for (const string& str : gifts)
    {
        stringstream ss(str);
        string Giver, Receiver;
        ss >> Giver >> Receiver;

        FriendMap[Giver].GiveGift(Receiver);
        FriendMap[Receiver].ReceiveGift(Giver);
    }

    // ���ǿ� ���� �����޿� ���� ���� ���� ���
    vector<int> NextMonthGift(FriendNum, 0);

    for (int Left = 0; Left < FriendNum; ++Left)
    {
        const string& LeftName = friends[Left];
        for (int Right = Left + 1; Right < FriendNum; ++Right)
        {
            const string& RightName = friends[Right];

            // ������ ���� Ƚ��
            int NumOfLeftGift = FriendMap[LeftName].GetCountOfGaveToFriend(RightName);
            int NumOfRightGift = FriendMap[RightName].GetCountOfGaveToFriend(LeftName);

           
            if (NumOfLeftGift > NumOfRightGift)  // Left�� ū ���
            {
                ++NextMonthGift[Left];
            }
            else if (NumOfLeftGift < NumOfRightGift)  // Right�� ū ���
            {
                ++NextMonthGift[Right];
            }
            else // ���� ��� ���� ������ �̿���.
            {
                int LeftPoint = FriendMap[LeftName].GetGiftPoint();
                int RightPoint = FriendMap[RightName].GetGiftPoint();

                if (LeftPoint > RightPoint)
                {
                    ++NextMonthGift[Left];
                }
                else if (LeftPoint < RightPoint)
                {
                    ++NextMonthGift[Right];
                }
            }
        }
    }

    // NextMonthGift���� ���� ū �� ã��
    int answer = *(std::max_element(NextMonthGift.begin(), NextMonthGift.end()));
    return answer;
}

int main()
{
    solution({ "joy", "brad", "alessandro", "conan", "david" }, { "alessandro brad", "alessandro joy", "alessandro conan", "david alessandro", "alessandro david" });
}