#include <string>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

std::vector<int> solution(std::vector<string> id_list, std::vector<string> report, int k) 
{
    std::vector<int> answer(id_list.size(), 0);

    // 신고자 index를 저장하기 위해서 unordered_map으로 이름과 index 저장
    std::unordered_map<std::string, int> Reports; 

    // 피신고자가 누구에게 신고를 당했는지를 알기위해 피신고자 마다 set<string>을 가짐
    // 이 set의 size를 통해 신고 횟수를 검사하여 k보다 크면 set에 있는 모든 신고자들에게 메시지를 뿌림
    std::unordered_map<std::string, std::set<string>> Respondents;

    int IdNumber = static_cast<int>(id_list.size());

    // 신고자와 피신고자 Eliment 삽입
    for (int i = 0; i < IdNumber; ++i)
    {
        Respondents[id_list[i]] = std::set<std::string>();
        Reports[id_list[i]] = i;
    }

    // 공백문자를 기준으로 각 피신고자에 신고자 추가
    for (const std::string str : report)
    {
        int index = static_cast<int>(str.find(" "));
        string Reporter = str.substr(0, index);
        string Respondent = str.substr(index + 1);

        Respondents[Respondent].insert(Reporter);
    }

    // 신고가 접수되면 신고자들 index에 1씩 추가 
    for (int i = 0; i < IdNumber; ++i)
    {
        std::string CurReporter = id_list[i];
        int ReportNumber = static_cast<int>(Respondents[CurReporter].size());
        if (k <= ReportNumber)
        {
            for (const std::string Respondent : Respondents[CurReporter])
            {
                ++answer[Reports[Respondent]];
            }
        }
    }
    return answer;
}  

int main()
{
    std::vector<string> id_list = { "muzi", "frodo", "apeach", "neo" };
    std::vector<string> report = { "muzi frodo", "apeach frodo", "frodo neo", "muzi neo", "apeach muzi" };

    std::vector<int> a = solution(id_list, report, 2);
    
}