#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

long long solution(vector<int> weights) 
{
    long long answer = 0;

    unordered_map<int, int> WeightMap;

    for (int Eliment : weights)
    {
        ++WeightMap[Eliment];
    }



    return answer;
}

int main()
{
    long long res = solution({ 100, 180, 360, 100, 270 });
}