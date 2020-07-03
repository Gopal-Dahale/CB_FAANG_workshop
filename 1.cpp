// generate all balanced parentheses
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print(vector<char> &v)
{
    for (auto &i : v)
        cout << i;

    cout << '\n';
}

void generate(vector<char> &a, int o, int c, int i, int n)
{
    if (i == 2 * n)
    {
        print(a);
        return;
    }
    // insert '('
    if (o < n)
    {
        a[i] = '(';
        generate(a, o + 1, c, i + 1, n);
    }
    // insert ')'
    if (o > c)
    {
        a[i] = ')';
        generate(a, o, c + 1, i + 1, n);
    }
}

int main()
{
    int n = 2; // 2 opening brackets and 2 closing brackets
    vector<char> a(2 * n);
    generate(a, 0, 0, 0, n);

    return 0;
}
