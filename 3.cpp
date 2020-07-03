#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    bool x;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));

    int dx[4]{1, -1, 0, 0};
    int dy[4]{0, 0, 1, -1};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> x;
            v[i][j] = x;
        }
    }

    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (v[i][j])
                q.push(make_pair(i, j));

    int res = -1;
    int r, c;
    while (!q.empty())
    {
        int s = q.size();
        for (int i = 0; i < s; i++)
        {
            pair<int, int> p = q.front();
            q.pop();

            for (int j = 0; j < 4; j++)
            {
                r = p.first + dx[j];
                c = p.second + dy[j];

                if ((r >= 0 && r < n && c >= 0 && c < m))
                {
                    if (v[r][c] == 0)
                    {
                        v[r][c] = true;
                        q.push(make_pair(r, c));
                    }
                }
            }
        }
        res++;
    }
    cout << res << "\n";
    return 0;
}
