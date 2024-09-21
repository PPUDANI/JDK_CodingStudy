
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

/*
 * Complete the 'extraLongFactorials' function below.
 *
 * The function accepts INTEGER n as parameter.
 */

string timeConversion(string s)
{
    stringstream ss;
    ss.str(s);

    string hour;
    std::getline(ss, hour, ':');

    string Back = s.substr(2, 6);
    string format = s.substr(8, 2);

    int formathour = stoi(hour);
    if (format == "PM" && stoi(hour) <= 12)
    {
        formathour += 12;

        if (formathour >= 24)
        {
            formathour -= 24;
        }
    }

    if (formathour < 10)
    {
        hour = '0';
    }

    hour += to_string(formathour);

    std::string Result = hour + Back;

    return Result;
}

int main()
{
    string a = timeConversion("06:01:01AM");
    return 0;
}