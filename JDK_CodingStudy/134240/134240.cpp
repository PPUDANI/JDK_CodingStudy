#include <string>
#include <vector>

using namespace std;
string solution(vector<int> food)
{
    std::string answer = "";

    int NumberOfFoodTypes = static_cast<int>(food.size());

    std::vector<std::string> Foods(NumberOfFoodTypes, "");


    for (int i = 0; i < NumberOfFoodTypes; ++i)
    {
        int NumberOfFood = food[i] / 2;
        Foods[i].assign(NumberOfFood, i + '0');
    }

    for (int i = 0; i < NumberOfFoodTypes; ++i)
    {
        answer += Foods[i];
    }

    answer += '0';

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
