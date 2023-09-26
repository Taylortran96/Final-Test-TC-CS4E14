#include <iostream>
#include <string>
#include <stack>
using namespace std;

string encodeString(const string &str)
{
    string encodedStr;
    stack<char> charStack;
    int count = 1;
    for (char c : str)
    {
        if (!charStack.empty() && c == charStack.top())
        {
            count++;
        }
        else
        {
            if (count > 1)
            {
                encodedStr += charStack.top() + to_string(count);
                count = 1;
            }
            charStack.push(c);
        }
    }
    if (count > 1)
    {
        encodedStr += charStack.top() + to_string(count);
    }
    return encodedStr;
}

int main()
{
    string input;
    cin >> input;
    string encodedString = encodeString(input);
    cout << "Encoded string: " << encodedString << endl;
    return 0;
}
