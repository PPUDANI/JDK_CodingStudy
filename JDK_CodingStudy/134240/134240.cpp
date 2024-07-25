#include <string>
#include <vector>

using namespace std;
string solution(vector<int> food)
{
    std::string answer = "";

    int NumberOfFoodTypes = static_cast<int>(food.size());

    // ���� �� ���ڿ��� ������ �����̳�
    std::vector<std::string> Foods(NumberOfFoodTypes, "");

    // ��ȸ�ϸ� ���ĸ����� ���ڿ��� ����� answer�� �߰�
    for (int i = 0; i < NumberOfFoodTypes; ++i)
    {
        int NumberOfFood = food[i] / 2;
        Foods[i].assign(NumberOfFood, i + '0'); 
        answer += Foods[i];
    }

    // 0 �߰�
    answer += '0';

    // Foods�� �������� ���� answer�� �߰�
    for (int i = NumberOfFoodTypes - 1; i >= 0; --i)
    {
        answer += Foods[i];
    }

    return answer;
}

int main()
{
    string res = solution({ 1, 3, 4, 6, 2, 4, 6, 7, 0});
}
