#include <iostream>
#include <vector>
#include <sstream>

int main()
{
    int numOfValues;
    std::vector<int> runningTotals;
    std::vector<int> pos;

    std::cout << "Enter number of distinct values: " << std::endl;
    std::cin >> numOfValues;

    std::cout << "Enter sequence of credits and debits: " << std::endl;
    int num;
    int runningTotal = 0;
    for (int i = 0; i < numOfValues; ++i)
    {
        std::cin >> num;
        runningTotal += num;
        runningTotals.push_back(runningTotal);
    }

    for (auto it = runningTotals.begin(); it != runningTotals.end(); ++it)
    {
        int prev = (it == runningTotals.begin()) ? 0 : *(it - 1);
        int next = (it == runningTotals.end() - 1) ? 0 : *(runningTotals.end() - 1) - *it;

        if (prev == next) pos.push_back(it - runningTotals.begin());
    }

    std::stringstream ss;
    for (auto j = pos.begin(); j != pos.end(); ++j)
    {
        ss << std::to_string(*j) << " ";
    }

    std::cout << ss.str() << std::endl; 
}
