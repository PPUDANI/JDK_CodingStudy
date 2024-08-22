#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer(1, arr[0]);

    for (int Num : arr)
    {
        // answer에 들어간 숫자와 같으면 넣지 않음.
        if (answer.back() != Num)
        {
            answer.push_back(Num);
        }
    }
    return answer;
}   

//
//vector<int> solution(vector<int> arr)
//{
//    vector<int> answer(1, arr[0]);
//
//    arr.erase(std::unique(arr.begin(), arr.end()), arr.end());
//
//    return arr;
//}
