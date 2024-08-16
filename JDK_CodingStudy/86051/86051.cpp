#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    // 0 ~ 9 ¥ı«œ±‚
    int answer = 45;

    for (int i : numbers)
    {
        answer -= i;
    }

    return answer;
}