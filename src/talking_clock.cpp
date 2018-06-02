#include <iostream>
#include <array>
#include <sstream>
using namespace std;

static const array<string, 4> tens = {"twenty", "thirty", "forty", "fifty"};
static const array<string, 19 > ones = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

string translateTime(int hour, int minute);

int main() 
{
    string time;
    cout << "Enter times (e.g. 12:05)" << endl;
    while (getline(cin, time)) {
        int hour = stoi(time.substr(0, 2));
        int minute = stoi(time.substr(3, 2));
        cout << "It's " << translateTime(hour, minute) << endl;
    }

    return 0;
}

// translate time in 12 hour format to written form
string translateTime(int hour, int minute)
{
    stringstream ss;
    ss << ones.at((hour + 11) % 12);

    if (minute == 0) ; // do nothing 
    else if (minute < 10) ss << " oh " <<  ones.at(minute - 1);
    else if (minute < 20) ss << " " << ones.at(minute - 1);
    else if (minute % 10) ss << " " << tens.at((minute / 10) - 2);
    else ss << tens.at((minute / 10) - 2) << " " << ones.at((minute % 10) - 1);

    ss << ((hour >= 12)? " pm" : " am");
    return ss.str();
}
