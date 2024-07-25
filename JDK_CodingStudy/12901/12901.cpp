#include <string>
#include <vector>

using namespace std;

// 2016년 한 달 30일을 기준으로 달 별 오차값을 구함
// 01 02 03 04 05 06 07 08 09 10 11
// 31 29 31 30 31 30 31 31 30 31 30
//                              -30
// --------------------------------
//  1 -1  1  0  1  0  1  1  0  1  0

// 월마다 누적되는 오차값을 더해준 값을 저장
// Index :  0  1  2  3  4  5  6  7  8  9 10 11
// Month :  1  2  3  4  5  6  7  8  9 10 11 12
// Error :     1 -1  1  0  1  0  1  1  0  1  0
// -------------------------------------------
//          0  1  0  1  1  2  2  3  4  4  5  5

string solution(int a, int b) 
{
	// 누적 오차
	std::vector<int> SumMonthError = { 0, 1, 0, 1, 1, 2, 2, 3, 4, 4, 5, 5 }; 

	// (Month - 1) * 30 + SumMonthError[Month - 1] + Day
	int NumberOfDays = --a * 30 + SumMonthError[a] + b; 

	// 일주일로 나눈 나머지를 구함.
	int CurDay = NumberOfDays % 7; 

	switch (CurDay) 	// 1월 1일이 금요일인 기준으로 작성
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