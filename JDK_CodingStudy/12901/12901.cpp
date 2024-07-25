#include <string>
#include <vector>

using namespace std;

// 2016�� �� �� 30���� �������� �� �� �������� ����
// 01 02 03 04 05 06 07 08 09 10 11
// 31 29 31 30 31 30 31 31 30 31 30
//                              -30
// --------------------------------
//  1 -1  1  0  1  0  1  1  0  1  0

// ������ �����Ǵ� �������� ������ ���� ����
// Index :  0  1  2  3  4  5  6  7  8  9 10 11
// Month :  1  2  3  4  5  6  7  8  9 10 11 12
// Error :     1 -1  1  0  1  0  1  1  0  1  0
// -------------------------------------------
//          0  1  0  1  1  2  2  3  4  4  5  5

string solution(int a, int b) 
{
	// ���� ����
	std::vector<int> SumMonthError = { 0, 1, 0, 1, 1, 2, 2, 3, 4, 4, 5, 5 }; 

	// (Month - 1) * 30 + SumMonthError[Month - 1] + Day
	int NumberOfDays = --a * 30 + SumMonthError[a] + b; 

	// �����Ϸ� ���� �������� ����.
	int CurDay = NumberOfDays % 7; 

	switch (CurDay) 	// 1�� 1���� �ݿ����� �������� �ۼ�
	{
	case 0: return "THU";
	case 1: return "FRI";
	case 2: return "SAT";
	case 3: return "SUN";
	case 4: return "MON";
	case 5: return "TUE";
	case 6: return "WED";
	default: return "";
	}
}

int main()
{
	string a = solution(1, 1);
	string b = solution(1, 8);
	string c = solution(2, 1);
}