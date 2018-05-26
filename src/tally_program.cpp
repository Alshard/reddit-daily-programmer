#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

// Returns a tally of scores for player a..e, where lowercase adds a point and uppercase subtracts a point
int main(int argc, char *argv[] )
{
    map<char, int> scores = {{'a', 0}, {'b', 0}, {'c', 0}, {'d', 0}, {'e', 0}};

    if (argc > 1) {
        string input(argv[1]);
        int len;
        len = input.length();
        for (int i = 0; i < len; ++i)
        {
            char n = input.at(i);

            if ((n >= 'a' && n <= 'e'))
            {
                scores[n]++;
            }
            else if (n >= 'A' && n <= 'E')
            {
                scores[tolower(n, locale())]--;
            }
            else
            {
                stringstream error;
                error << "Invalid input found at position " << to_string(i) << ": " << argv[i];
                throw invalid_argument(error.str());
            }

        }
    }

    // sort the scores by value
    vector<pair<char, int>> mapVector;
    for (auto j = scores.begin(); j != scores.end(); ++j)
    {
        mapVector.push_back(*j);
    }
    sort(mapVector.begin(), mapVector.end(), [](const pair<char, int> &l, const pair<char, int> &r) {
            return l.second > r.second;
            });

    // output result
    for (auto k = mapVector.begin(); k != mapVector.end(); ++k)
    {
        cout << string(1, k->first) << ":" << to_string(k->second);
        if (k != mapVector.end())
        {
            cout << ", ";
        }
    }
    cout << endl;

    return 0;
}

