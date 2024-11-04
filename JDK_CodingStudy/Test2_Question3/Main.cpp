#include<iostream>
#include<vector>
#include<string>
#include <cctype>
using namespace std;

int IsAlpha(int _Ascii)
{
	if (_Ascii >= 'A' && _Ascii <= 'Z')
	{
		return 1;
	}
	else if (_Ascii >= 'a' && _Ascii <= 'z')
	{
		return 2;
	}
	return 0;
}

string caesarCipher(string s, int k) 
{
	string NewStr = "";

	k %= 26;

	for (int Ascii : s)
	{
		int Alpha = IsAlpha(Ascii);
		if (Alpha > 0)
		{
			Ascii += k;
		}
		
		if (Alpha == 1 && Ascii > 'Z' ||
			Alpha == 2 && Ascii > 'z')
		{
			Ascii -= 26;
		}

		NewStr += char(Ascii);
	}

	return NewStr;
}

int main()
{
	string res2 = caesarCipher("www.abc.xy", 87); // fff.jkl.gh
	
}