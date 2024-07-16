//#include <string>
//#include <vector>
//#include <unordered_map>
//
//using namespace std;
//
//string solution(vector<string> participant, vector<string> completion) {
//    string answer = "";
//
//    unordered_map<string, int> Players;
//
//    for (string Player : completion)
//    {
//        if (Players.count(Player) <= 0)
//        {
//            Players.insert({ Player , 0 });
//            ++Players[Player];
//        }
//        else
//        {
//            ++Players[Player];
//        }
//    }
//
//    string P = "";
//    for (string Goal : participant)
//    {
//        if (Players.count(Goal) > 0)
//        {
//            
//        }
//    }
//    return answer;
//}

#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    

    unordered_set<string> Players;

    for (string Player : completion)
    {
        Players.insert(Player);
    }

    for (string Goal : participant)
    {
        Players.erase(Goal);
    }

    string answer = Players.begin()->data();
    return answer;
}

int main()
{
    vector<string> a = { "leo", "kiki", "eden" };
    vector<string> b = { "eden", "kiki" };

    string c = solution(a, b);
}