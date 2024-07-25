#include <string>
#include <vector>

using namespace std;
string solution(vector<int> food)
{
    std::string answer = "";

    int NumberOfFoodTypes = static_cast<int>(food.size());

    // 음식 별 문자열을 저장할 컨테이너
    std::vector<std::string> Foods(NumberOfFoodTypes, "");

    // 순회하며 음식마다의 문자열을 만들고 answer에 추가
    for (int i = 0; i < NumberOfFoodTypes; ++i)
    {
        int NumberOfFood = food[i] / 2;
        Foods[i].assign(NumberOfFood, i + '0'); 
        answer += Foods[i];
    }

    // 0 추가
    answer += '0';

    // Foods를 역순으로 돌아 answer에 추가
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
