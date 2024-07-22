#include <string>
#include <vector>

using namespace std;

// <2016년 한 달 30일을 기준으로 달 별 오차값>
// 01 02 03 04 05 06 07 08 09 10 11
//  1,-1, 1, 0, 1, 0, 1, 1, 0, 1, 0

// <오차 누적 계산>
//  1, 0, 1, 1, 2, 2, 3, 4, 4, 5, 5

// 월마다 누적되는 오차값을 더해준 값을 저장
// Index : 00 01 02 03 04 05 06 07 08 09 10 11
// Month : 01 02 03 04 05 06 07 08 09 10 11 12
//          0, 1, 0, 1, 1, 2, 2, 3, 4, 4, 5, 5

string solution(int a, int b) 
{
	std::vector<int> SumMonthError = { 0, 1, 0, 1, 1, 2, 2, 3, 4, 4, 5, 5 };

	int NumberOfDays = --a * 30 + SumMonthError[a] + b; // (달 수 - 1) * 30 + (달 수 - 1)의 오차값 + 일 수
	int CurDay = NumberOfDays % 7; // 일주일로 나눈 나머지를 구함.

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