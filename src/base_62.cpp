#include <iostream>
#include <string>
using namespace std;

const string alphabet = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
const int base = 62;

int main()
{
    unsigned long long n;
    cout << "Enter number to convert:" << endl;

    cin >> n;

    string result;
    while (n > 0)
    {
        int r = n % base;
        n = n / base;
        result = alphabet.at(r) + result;
    }

    cout << "Your number in base " << base << " is: " << result << endl;
}
