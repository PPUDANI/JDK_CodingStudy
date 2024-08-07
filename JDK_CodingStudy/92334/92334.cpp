#include <string>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

std::vector<int> solution(std::vector<string> id_list, std::vector<string> report, int k) 
{
    std::vector<int> answer(id_list.size(), 0);

    // �Ű��� index�� �����ϱ� ���ؼ� unordered_map���� �̸��� index ����
    std::unordered_map<std::string, int> Reports; 

    // �ǽŰ��ڰ� �������� �Ű� ���ߴ����� �˱����� �ǽŰ��� ���� set<string>�� ����
    // �� set�� size�� ���� �Ű� Ƚ���� �˻��Ͽ� k���� ũ�� set�� �ִ� ��� �Ű��ڵ鿡�� �޽����� �Ѹ�
    std::unordered_map<std::string, std::set<string>> Respondents;

    int IdNumber = static_cast<int>(id_list.size());

    // �Ű��ڿ� �ǽŰ��� Eliment ����
    for (int i = 0; i < IdNumber; ++i)
    {
        Respondents[id_list[i]] = std::set<std::string>();
        Reports[id_list[i]] = i;
    }

    // ���鹮�ڸ� �������� �� �ǽŰ��ڿ� �Ű��� �߰�
    for (const std::string str : report)
    {
        int index = static_cast<int>(str.find(" "));
        string Reporter = str.substr(0, index);
        string Respondent = str.substr(index + 1);

        Respondents[Respondent].insert(Reporter);
    }

    // �Ű� �����Ǹ� �Ű��ڵ� index�� 1�� �߰� 
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