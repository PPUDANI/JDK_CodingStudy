#include <string>
#include <vector>
#include <algorithm>

int SortDataIndex = -1;

// sort_by �������� ����
bool compare(const std::vector<int>& Left, const std::vector<int>& Right)
{
    return Left[SortDataIndex] < Right[SortDataIndex];
}

// ext, sort_by������ index�� ��ȯ���ִ� �Լ�
int GetDataIndex(const char _ext)
{
    switch (_ext)
    {
    case 'c': 
        return 0;
    case 'd': 
        return 1;
    case 'm': 
        return 2;
    case 'r': 
        return 3;
    default : 
        return -1;
    }
}

std::vector<std::vector<int>> solution(std::vector<std::vector<int>> data, std::string ext, int val_ext, std::string sort_by)
{
    std::vector<std::vector<int>> answer;
    answer.reserve(data.size());

    // ext�� sort_by�� GetDataIndex()�Լ��� ���� index�� �޾ƿ�
    int CheckDataIndex = GetDataIndex(ext[0]);
    SortDataIndex = GetDataIndex(sort_by[0]);

    for (std::vector<int>& Data : data)
    {
        // �޾ƿ� CheckDataindex�� �����͸� ����.
        if (Data[CheckDataIndex] < val_ext)
        {
            answer.push_back(Data);
        }
    }

    // ����
    std::sort(answer.begin(), answer.end(), compare);
  
    return answer;
}

int main()
{
    solution({ { 1, 20300104, 100, 80 }, { 2, 20300804, 847, 37 }, { 3, 20300401, 10, 8 } }, "date", 20300501, "remain");
}