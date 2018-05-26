#include <iostream>
#include <array>
#include <string>
#include <sstream>
using namespace std;

const array<array<bool, 9>, 10> numbers = {{
    {false, true, false, true, false, true, true, true, true},
    {false, false, false, false, false, true, false, false, true},
    {false, true, false, false, true, true, true, true, false},
    {false, true, false, false, true, true, false, true, true},
    {false, false, false, true, true, true, false, false, true},
    {false, true, false, true, true, false, false, true, true},
    {false, true, false, true, true, false, true, true, true},
    {false, true, false, false, false, true, false, false, true},
    {false, true, false, true, true, true, true, true, true},
    {false, true, false, true, true, true, false, true, true}}};

string decode(array<bool, 9> cipher);

// Deciphers 3 lines of input visually representing 9 digits
int main(int argc, char* argv[]) 
{
    array<bool, 27 * 3> cipher;     // single array to store the cipher, with second row at pos + 27, third row at pos + (2 * 27)

        cout << "Enter cipher:" << endl;
    
    int line = 1;
    for (int i = 0; i < 3; ++i) 
    {
        string next;
        getline(cin, next);

        for (int j = 0; j < 27; ++j) 
        {
            cipher[((line - 1) * 27) + j] = string(1, next.at(j)) != " "; 
        }
        line++;
    };

    stringstream result;
    for (int k = 0; k < 9; ++k)
    {
        array<bool, 9> num;
        for (int z = 0; z < 3; z++)
        {
            for (int l = 0; l < 3; l++)
            {
                num[(z * 3) + l] = cipher[(k * 3) + (z * 27) + l];
            }
        }
        result << decode(num);
    }
    cout << result.str() << endl;
    return 0;
}

string decode(array<bool, 9> cipher)
{
   int count = 0;
    for (auto it = numbers.begin(); it != numbers.end(); ++it)
    {
        bool match = true;
        for (int i = 0; i < 9; ++i)
        {
            if (cipher[i] != it->at(i))
            {
                match = false;
                break;
            }
        };

        if (match) 
        {
            return to_string(count);
        }
        count++;
    }

    return "null";
} 
