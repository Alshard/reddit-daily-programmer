#include <iostream>
#include <string>
#include <limits>

int invert(int n);
int abs(int n);
int negate(int n);
int sub(int a, int b);
int divide(int a, int b);
int mul(int a, int b);
int pow(int a, int b);

int main()
{
    bool quit = false;

    std::cout << "Welcome to the adding calculator. Enter your input as A <operation> B. Enter 'q' to exit." << std::endl;


    while (!quit)
    {
        std::string input;
        std::cin >> input;

        if (input == "q") 
        {
            quit = true;
            break;
        }

        int a, b;
        std::string op;

        try 
        {
            a = std::stoi(input);
            std::cin >> op;
            std::cin >> b;

            if (!std::cin.good()) throw std::invalid_argument("NaN");

            if (op == "+") std::cout << std::to_string(a + b) << std::endl;
            else if (op == "-") std::cout << std::to_string(sub(a, b)) << std::endl;
            else if (op == "*") std::cout << std::to_string(mul(a, b)) << std::endl;
            else if (op == "/") std::cout << std::to_string(divide(a, b)) << std::endl;
            else if (op == "^") std::cout << std::to_string(pow(a, b)) << std::endl;
        }
        catch (const std::invalid_argument err)
        {
            std::cerr << "Invalid input" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        catch(const char* msg)
        {
            std::cerr << msg << std::endl;
        }
    }
    return 0;
}

int abs(int n)
{
    return (n < 0)? negate(n) : n;
}

int mul(int a, int b)
{
    if (a == 0 || b == 0) return 0;

    if (a < 0 && b < 0)
    {
        a = abs(a);
        b = abs(b);
    }
    else if (a > 0 && b < 0)
    {
        // swap a and b
        int temp = a;
        a = b;
        b = temp;
    }

    int result = a;
    for (int i = 1; i < b; ++i)
    {
        result += a;
    }
    return result;
}

int negate(int n)
{
    short MIN = (short) 32768;    // min signed int value for 16 bits 

    while (MIN + n != 0)
    {
        MIN++;
    }
    return MIN;
}

int sub(int a, int b)
{
    return (b < 0) ? a + negate(b) : a + b;
}

int divide(int a, int b)
{
    if (b == 0) throw "Not-defined";
    if (b == 1) return a;

    int i = (a < 0) ? abs(a) : a;
    int j = (b < 0) ? abs(b) : b;

    if (j > i) throw "Non-integral answer";

    int count = 1;
    int value;
    for (value = j; value < i; value += j)
    {
        count++; 
    }

    if (value != i) throw "Non-integral answer";

    return ((a < 0 && b > 0) || (a > 0 && b < 0)) ? negate(count) : count; 

}

int pow(int a, int b)
{
    if (a == 0) return 0;
    if (b == 0 || b == -1) return 1;

    if (b < -1) throw "Non-integral answer";
    else 
    {
        int count = 1;
        int result = a;
        while (count < b)
        {
            result = mul(result, a);
            count++; 
        }
        return result;
    }
}
