#include <iostream>
#include <string>
#include <array>
using namespace std;

const std::array<string, 7> weekdays = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};

// Calculates the weekday of a given date using Zeller's congruence
int main()
{
    int year, month, day;

    cout << "Enter date: " << endl;
    cin >> year;
    cin >> month;
    cin >> day;

    if (month <= 2)
    {
        month += 12;
        year--;
    }

    int zeroBasedCentury = year / 100;
    int yearOfCentury = year % 100;

    int dayNumber = (day + ((13 * (month + 1)) / 5) + yearOfCentury + (yearOfCentury / 4) + (zeroBasedCentury / 4) + (5 * zeroBasedCentury)) % 7;
    cout << "The weekday is " << weekdays[dayNumber] << "." << endl;

    return 0;
}
