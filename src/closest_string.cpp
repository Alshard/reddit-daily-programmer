#include <iostream>
#include <vector>
#include <string>
using namespace std;

int hamming(string a, string b);

// Brute force method of finding the closest string for a sequence of strings using hamming distance
int main()
{
    vector<string> strs;
    string next;
    int n;

    cout << "Enter number of strings:" << endl;
    cin >> n;
    cout << "Enter " << to_string(n) << " strings: " << endl;

    cin.ignore();
    for (int i = 0; i < n; ++i)
    {
        getline(cin, next);
        strs.push_back(next);
    }

    int lowest = -1;
    string closest;
    for (int j = 0; j < n; ++j)
    {
        int score = 0;
        for (int k = 0; k < n; ++k)
        {
            score += hamming(strs.at(j), strs.at(k));
        }

        if (lowest == -1 || score < lowest) 
        {
            lowest = score;
            closest = strs.at(j);
        }
    }

    cout << "The closest string is: " << closest << endl;
}

int hamming(string a, string b)
{
    if (a.length() == b.length())
    {
        int dis = 0;
        for (int i = 0; i < (int) a.length(); ++i)
        {
            if (a.at(i) != b.at(i))
            {
                dis++;
            }
        }
        return dis;
    }
    return 1;
}
