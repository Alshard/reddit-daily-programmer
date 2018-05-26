#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
using namespace std;

// Calculates the regular paper folding sequence
int main(int argc, char* argv[])
{
    string seq = "1";
    int cycles = 9;

    for (int i = 1; i < cycles; ++i) 
    {
        stringstream next;
        next << "1";
        int count = 0;

        for (int j = 0; j < (int) seq.length(); ++j)
        {
            next << seq.at(j) << ((count % 2)? "1" : "0");
            count++;
        }
        seq = next.str();
    }

    cout << seq << endl;
    return 0;
}
