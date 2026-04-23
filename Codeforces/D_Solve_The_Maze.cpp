// Author:  Rajesh Biswas
// CF    :  rajesh_1920
// Date  :  14.01.2026

#include <bits/stdc++.h>
using namespace std;
//----------------------------(definition section)-----------------------------------------
#define dbg(x) cout << #x << " = " << x << '\n';
#define fi first
#define sc second

#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()

const double eps = 1e-1;
const int inf = 1e16 + 7;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;
//------------------------------(solve)----------------------------------------------------
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> v(n, vector<char>(m));
    for (auto &it : v)
        for (auto &ii : it)
            cin >> ii;
    vector<int> dx = {0, 0, -1, 1}, dy = {1, -1, 0, 0};
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (v[i][j] == 'B')
                for (int ii = 0; ii < 4; ii++)
                {
                    int tx = i + dx[ii], ty = j + dy[ii];
                    if (tx >= 0 && tx < n && ty >= 0 && ty < m)
                    {
                        if (v[tx][ty] == 'G')
                        {
                            cout << "No\n";
                            return;
                        }
                        if (v[tx][ty] != 'B')
                            v[tx][ty] = '#';
                    }
                }

    queue<pair<int, int>> q;
    vector<vector<int>> vis(n, vector<int>(m, 0));
    if (v[n - 1][m - 1] != '#')
        q.push({n - 1, m - 1}), vis[n - 1][m - 1] = 1;
    while (!q.empty())
    {
        int x = q.front().fi, y = q.front().sc;
        q.pop();
        for (int ii = 0; ii < 4; ii++)
        {
            int tx = x + dx[ii], ty = y + dy[ii];
            if (tx >= 0 && tx < n && ty >= 0 && ty < m &&
                vis[tx][ty] == 0 && v[tx][ty] != '#')
                vis[tx][ty] = 1, q.push({tx, ty});
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (v[i][j] == 'G' && vis[i][j] == 0)
            {
                cout << "No\n";
                return;
            }
    cout << "Yes\n";
}
signed main()
{
    // cout << fixed << showpoint << setprecision(10);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1, T;
    cin >> test;
    for (T = 1; T <= test; T++)
    {
        // cout << "Case " << T << ": ";
        solve();
    }
    return 0;
}