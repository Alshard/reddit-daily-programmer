#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int findNextCharPos(string& str, int start, char c);
string encrypt(string message, int cols, int rows, bool rotateClockwise);
string route_cipher(string str);

int main()
{
    cout << route_cipher("\"WE ARE DISCOVERED. FLEE AT ONCE\" (9, 3) clockwise") << endl;
    cout << route_cipher("\"why is this professor so boring omg\" (6, 5) counter-clockwise") << endl;
    cout << route_cipher("\"Solving challenges on r/dailyprogrammer is so much fun!!\" (8, 6) counter-clockwise") << endl;
    cout << route_cipher("\"For lunch let's have peanut-butter and bologna sandwiches\" (4, 12) clockwise") << endl;
    cout << route_cipher("\"I've even witnessed a grown man satisfy a camel\" (9,5) clockwise") << endl;
    cout << route_cipher("\"Why does it say paper jam when there is no paper jam?\" (3, 14) counter-clockwise") << endl;

    return 0;
}

// Find the next index of a char in a string from a starting position 
int findNextCharPos(string& str, int start, char c)
{
    int pos = start;
    while (str.at(pos) != c) pos++;
    return pos;
}

// Parse input for a message to be encrypted with spiral route cipher
string route_cipher(string str) 
{
    int messageEnd = findNextCharPos(str, 1, '"');
    string message = str.substr(1, messageEnd - 1);
    int comma = findNextCharPos(str, messageEnd, ',');
    int cols = stoi(str.substr(messageEnd + 3, comma - (messageEnd + 3)));
    int lastSpace = findNextCharPos(str, comma + 2, ' ');
    int rows = stoi(str.substr(comma + 1, lastSpace - (comma + 1)));
    bool dir = str.substr(lastSpace + 1, str.length() - (lastSpace + 1)) == "clockwise";

    return encrypt(message, cols, rows, dir);
}

// Encrypt a message using a spiral route cipher algorithm
string encrypt(string message, int cols, int rows, bool rotateClockwise) 
{
    for (char &c: message) c = toupper(c);  // convert message to uppercase

    // remove non alphabetic chars
    stringstream str;
    for (auto it = message.begin(); it != message.end(); ++it) {
        if (*it < 'A' || *it > 'Z') continue;
        else str << *it;
    }
    message = str.str();

    int dir = (rotateClockwise)? 2 : 3;        // up = 0, right = 1, down = 2, left = 3
    int x = cols - 1;   // starting col
    int y = 0;          // starting row
    // markers for grid rows and cols visited
    int top = -1;
    int right = cols;
    int bottom = rows;
    int left = -1;

    int encrypted = 0;  // number of chars encrypted in message
    stringstream res;

    while (encrypted < cols * rows) {
        int index = (y * cols) + x;
        char next = (index > message.length() - 1)? 'X' : message.at(index);
        res << next;
        encrypted++;

        // change direction if needed
        if (dir == 0 && y - 1 == top) {             // moving up
            dir = (rotateClockwise)? dir + 1 : dir - 1;
            if (rotateClockwise) left++;
            else right--;
        } else if (dir == 1 && x + 1 == right) {    // moving right
            dir = (rotateClockwise)? dir + 1 : dir - 1;
            if (rotateClockwise) top++;
            else bottom--;
        } else if (dir == 2 && y + 1 == bottom) {   // moving down
            dir = (rotateClockwise)? dir + 1 : dir - 1;
            if (rotateClockwise) right--;
            else left++;
        } else if (dir == 3 && x - 1 == left) {     // moving left
            dir = (rotateClockwise)? dir + 1 : dir - 1;
            if (rotateClockwise) bottom--;
            else top++;
        }

        // make sure direction is 0..3
        if (dir == -1) dir = 3;
        else if(dir == 4) dir = 0;

        // move current pos
        if (dir == 0) y--;
        else if (dir == 1) x++;
        else if (dir == 2) y++;
        else if (dir == 3) x--;
    }

    return res.str();
}
