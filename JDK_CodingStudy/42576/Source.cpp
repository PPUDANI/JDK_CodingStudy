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

    unordered_multiset<string> Players;

    for (string Player : participant)
    {
        Players.insert(Player);
    }

    for (string Goal : completion)
    {
        auto iter = Players.find(Goal);
        Players.erase(iter);
    }

    string answer = Players.begin()->data();
    return answer;
}

int main()
{
    vector<string> a = { "mislav", "stanko", "mislav", "ana" };
    vector<string> b = { "stanko", "ana", "mislav" };

    string c = solution(a, b);
}