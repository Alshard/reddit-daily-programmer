#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string encrypt(string keyword, string message);
string decrypt(string keyword, string code);

int main()
{

    string keyword, message, encrypted;
    cout << "Enter the secret word and message to encrypt separated by a space:" << endl;
    cin >> keyword;
    cin >> message;

    encrypted = encrypt(keyword, message);
    cout << "The encrpted message is: " << encrypted << endl;
    cout << "The decrypted message is: " << decrypt(keyword, encrypted) << endl;

    cout << "Challenge output:" << endl;
    cout << decrypt("cloak", "klatrgafedvtssdwywcyty") << endl;
    cout << decrypt("python", "pjphmfamhrcaifxifvvfmzwqtmyswst") << endl;
    cout << decrypt("moore", "rcfpsgfspiecbcc") << endl;
}

string encrypt(string keyword, string message)
{
    stringstream ss;
    for (int i = 0; i < (int) message.length(); ++i)
    {
        int a = message.at(i) - 'a';
        int b = keyword.at(i % keyword.length()) - 'a';

        char result = ((a + b) % 26) + 'a';
        ss << result; 
    } 
    return ss.str();
}

string decrypt(string keyword, string code)
{
    stringstream ss;
    for (int i = 0; i < (int) code.length(); ++i)
    {
        int a = code.at(i) - 'a';
        int b = keyword.at(i % keyword.length()) - 'a';
        
        int result = a - b;
        if (result < 0) 
        {
            result += 26;
        }
        ss << static_cast<char>(result + 'a');
    }
    return ss.str();
}
