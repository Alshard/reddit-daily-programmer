#include <iostream>
#include <sstream>
#include <string>
using namespace std;

void outputBowlingFrames(string str);
int nextNum(string str, int& index);

int main() 
{
    outputBowlingFrames("6 4 5 3 10 10 8 1 8 0 10 6 3 7 3 5 3");
    outputBowlingFrames("9  0  9  0  9  0  9  0  9  0  9  0  9  0  9  0  9  0  9  0 ");
    outputBowlingFrames("10 10 10 10 10 10 10 10 10 10 10 10");
    outputBowlingFrames("5  5  5  5  5  5  5  5  5  5  5  5  5  5  5  5  5  5  5  5  5");
    outputBowlingFrames("10 3  7  6  1  10 10 10 2  8  9  0  7  3  10 10 10");
    outputBowlingFrames("9  0  3  7  6  1  3  7  8  1  5  5  0  10 8  0  7  3  8  2  8");
    return 0;
}

void outputBowlingFrames(string str)
{
    stringstream ss;
    int index = 0;
    for (int i = 1; i < 10; ++i) {
        int firstAttempt = nextNum(str, index);
        if (firstAttempt == 10) ss << "X  ";
        else {
            ss << firstAttempt;
            int secondAttempt = nextNum(str, index);
            if (secondAttempt == 0) ss << "-";
            else if (firstAttempt + secondAttempt == 10) ss << "/";
            else ss << secondAttempt;
            ss << " ";
        }
    }

    int lastAttemptOne = nextNum(str, index);
    int lastAttemptTwo = nextNum(str, index);
    int lastAttemptThree = nextNum(str, index);

    ss << ((lastAttemptOne == 10)? "X" : to_string(lastAttemptOne));
    if (lastAttemptTwo == 10) ss << "X" << ((lastAttemptThree == 10)? "X" : to_string(lastAttemptThree));
    else if (lastAttemptTwo == 0) ss << "-";
    else if (lastAttemptTwo + lastAttemptOne == 10) ss << "/" << ((lastAttemptThree == 10)? "X" : to_string(lastAttemptThree));
    else ss << lastAttemptTwo;

    cout << ss.str() << endl;
}

// Find the next number in a string from the given index
int nextNum(string str, int &index) 
{
    while (index < str.length() && str.at(index) == ' ') {
        index++;
    }
    if (index == str.length()) return -1;

    int result;
    if (str.at(index) == '1' && index <= str.length() - 2 && str.at(index + 1) == '0') result = 10;
    else result = stoi(string(1, str.at(index)));

    index += ((result == 10)? 2 : 1); 
    return result;
}
