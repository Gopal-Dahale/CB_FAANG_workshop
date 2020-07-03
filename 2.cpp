//Given a parentheses string, return the minimum number of parentheses we must add to make the resulting string valid.
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    stack<char> s;
    string x;
    getline(cin, x);

    for (int i = 0; i < x.size(); i++)
    {
        if (x[i] == '(')
            s.push(x[i]);
        else if (x[i] == ')')
        {
            if (s.size() > 0 and s.top() == '(')
                s.pop();
            else
                s.push(x[i]);
        }
        
    }
    cout << s.size() << "\n";

    return 0;
}
