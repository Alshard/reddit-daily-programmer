#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int baum(int n);
void printBaumSeq(int n);

int main() 
{
    printBaumSeq(20);
}

void printBaumSeq(int n)
{
    for (int i = 0; i <= n; ++i) {
        if (i != 0) cout << ", ";
        cout << baum(i);
    }
    cout << endl;
}

// Check if index parameter is 0 or 1 in the baum sequence
int baum(int n) 
{
    int zeroCount = 0;
    int bit = 1;

    for (int j = 0; j < sqrt(n) + 1; ++j) {
        if (((bit << j) & n) == 0) zeroCount++;
         else {
            // check if consecutive zeroes of odd length found
            if (zeroCount % 2 == 1) {
                return 0;
            } else zeroCount = 0;
        } 
    }
    return 1;
}
