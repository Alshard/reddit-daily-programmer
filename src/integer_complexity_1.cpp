#include <iostream>
#include <string>
#include <math.h>
#include <chrono>

using namespace std;

int main()
{
  bool quit = false;
  
  while (!quit)
  {
    long long input;
    cout << "Enter input number" << endl;
    cin >> input;
    
    auto start = std::chrono::high_resolution_clock::now();
    for (long long i = sqrt(input); i >= 0; --i)
    {
        if (input % i == 0) 
        {
            cout << "The smallest possible value of B + C, given B * C = A is: " << to_string(i + (input / i)) << endl;
            break;
        }
    }
    
    auto stop = std:: chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = stop - start;
    cout << "Elapsed time was: " << elapsed.count() << endl;
    
    string cont;
    cout << "Continue? (y/n)" << endl;
    cin >> cont;
    quit = (cont != "y");
  }
}