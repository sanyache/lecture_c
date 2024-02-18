#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string s;
    cin >> s;
    vector<char> stack;
    for (char ch : s)
    {
        if (ch == '*')
        {
            if (!stack.empty())
            {
                stack.pop_back();
            }
        }
        else
        {
            stack.push_back(ch);
        }
    }
    cout << "Items left on the stack: ";
    for (char ch : stack)
    {
        cout << ch;
    }
    cout << endl;

    return 0;
}
