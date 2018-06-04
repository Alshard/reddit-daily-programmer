#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

int parseNextNum(string& str, int& index);
void partner(string& programs, vector<int>& pos, int a, int b);
void exchange(string& programs, vector<int>& pos, int a, int b);
void spin(string& programs, vector<int>& pos, int moves);
void permutePrograms(string programs, string moves);
void printPos(vector<int>& pos);

int main() 
{
    permutePrograms("abcde", "s1,x3/4,p4/1");
    permutePrograms("dbagcfe", "s4,s5,x5/3,x5/6,s5,s3,x0/3,x3/6,x6/0,x2/3,x3/5,s5,s5,s5,s1,s5,s3,s3,x2/3,x1/0,s1,s1,s1,s4,x1/3,x4/2,x5/1,x6/0,s2,x2/1");
}

void permutePrograms(string programs, string moves)
{
    int index = 0;
    vector<int> pos(programs.length());
    iota(pos.begin(), pos.end(), 0);

    while (index < moves.length()) {
        char move = moves.at(index);
        index++;
        int first = parseNextNum(moves, index);

        if (move == 's') spin(programs, pos, first);
        else {
            index++;    // move past fowardslash
            int second = parseNextNum(moves, index);
            if (move == 'x') exchange(programs, pos, first, second);
            else partner(programs, pos, first, second);
        }
        index++;    // consume comma;
    }

    cout << programs << endl;
}

void printPos(vector<int>& pos) 
{
    for (int i = 0; i < pos.size(); ++i) {
        if (i == 0) cout << pos.at(i);
        else cout << ", " << pos.at(i);
    }
    cout << endl;
}

int parseNextNum(string& str, int& index) 
{
    stringstream num;
    while (index < str.length() && str.at(index) >= '0' && str.at(index) <= '9') {
        num << str.at(index);
        index++;
    }
    return stoi(num.str());
}

void spin(string& programs, vector<int>& pos, int moves)
{
    int m = moves % programs.length();
    stringstream ss;
    ss << programs.substr(programs.length() - moves, moves) << programs.substr(0, programs.length() - moves);
    programs = ss.str();

    for (int& p : pos) {
        p = (p + moves) % programs.length();
    }
}

void exchange(string& programs, vector<int>& pos, int a, int b)
{
    char temp = programs.at(a);
    programs.at(a) = programs.at(b);
    programs.at(b) = temp;

    int index = -1;
    for (int i = 0; i < pos.size(); ++i) {
        if (pos.at(i) == a || pos.at(i) == b) {
            if (index == -1) index = i;
            else {
                int value = pos.at(index);
                pos.at(index) = pos.at(i);
                pos.at(i) = value;
            }
        }
    }
}

void partner(string& programs, vector<int>& pos, int a, int b)
{
    char temp = programs.at(pos.at(a));
    programs.at(pos.at(a)) = programs.at(pos.at(b));
    programs.at(pos.at(b)) = temp;

    // swap current logical positions of programs
    int tempPos = pos.at(a);
    pos.at(a) = pos.at(b);
    pos.at(b) = tempPos;
}
