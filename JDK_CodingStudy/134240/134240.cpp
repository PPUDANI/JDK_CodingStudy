#include <string>
#include <vector>

using namespace std;
string solution(vector<int> food)
{
    std::string answer = "";

    int NumberOfFoodTypes = static_cast<int>(food.size());

    // Food �� string ������ �����̳�
    std::vector<std::string> Foods(NumberOfFoodTypes, "");

    // ��ȸ�ϸ� Food string�� ����� answer�� �߰�
    for (int i = 0; i < NumberOfFoodTypes; ++i)
    {
        int NumberOfFood = food[i] / 2;
        Foods[i].assign(NumberOfFood, i + '0'); 
        answer += Foods[i];
    }

    // 0 �߰�
    answer += '0';

    // �������� answer�� �߰�
    for (int i = NumberOfFoodTypes - 1; i >= 0; --i)
    {
        answer += Foods[i];
    }

    return answer;
}

/*
string solution(vector<int> food)
{
    std::string answer = "";

    int NumberOfFoodTypes = static_cast<int>(food.size());
    std::vector<std::string> Foods(NumberOfFoodTypes, "");

    for (int i = 0; i < NumberOfFoodTypes; ++i)
    {
        int NumberOfFood = food[i] / 2;
        Foods[i].assign(NumberOfFood, i + '0');
        answer += Foods[i];
    }

    answer += '0';

    for (int i = answer.size() - 2; i >= 0; --i)
    {
        answer += answer[i];
    }

    return answer;
}
*/
int main()
{
    string res = solution({ 1, 3, 4, 6, 2, 4, 6, 7, 0});
}
