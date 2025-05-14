#include <bits/stdc++.h>

using namespace std;

std::string formatTwoDigits(const int num)
{
    if (num > 10)
        return to_string(num);
    else
        return "0" + to_string(num);
}

string timeConversion(const std::string& s) 
{
    int hours   {};
    int minutes {};
    int seconds {};
    std::string meridiem {};
    
    int numbers_found = 0;
    size_t starting_int_idx = 0;

    for (int i = 0; i < s.size(); i++)
    {   
        if (isdigit(s[i]))
            continue;
        
        std::string element {};

        if (toupper(s[i]) == 'M')
        {
            meridiem = s.substr(i - 1, 2);
            break;
        }
        else
            element = s.substr(starting_int_idx, i - starting_int_idx);

        switch (numbers_found)
        {
        case 0:
            hours = stoi(element);
            break;
        case 1:
            minutes = stoi(element);
            break;
        case 2:
            seconds = stoi(element);
            break;
        default:
            break;
        }

        starting_int_idx = i + 1;
        numbers_found++;
    }

    if (meridiem == "PM")
        hours += 12;
    
    if (hours >= 12)
        hours %= 12;

    std::ostringstream oss {};
    oss << formatTwoDigits(hours) << ':' << formatTwoDigits(minutes) << ':' << formatTwoDigits(seconds) << '\n';

    return oss.str();
}

int main()
{
    // ofstream fout(getenv("OUTPUT_PATH"));
    string s;
    s = "12:40:22AM";

    string result = timeConversion(s);
    std::cout << result << '\n';

    // fout.close();

    return 0;
}
