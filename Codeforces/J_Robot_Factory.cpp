// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  28.08.2025

#include <bits/stdc++.h>
using namespace std;
//----------------------------(definition section)-----------------------------------------
#define dbg(x) cout << #x << " = " << x << '\n';
// #define int long long int
#define fi first
#define sc second

#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()

// const double eps = 1e-1;
// const int inf = 9e16 + 7;
// const int MOD = 1e9 + 7;
// const int N = 1e5 + 10;
//------------------------------(solve)----------------------------------------------------
void dfs(int i, int j, vector<vector<int>> &v, vector<vector<bool>> &vis, int &st)
{
    st++;
    vis[i][j] = true;
    int t = v[i][j];
    if (!(t & 1))
        if ((!(v[i][j - 1] & (1 << 2))) && vis[i][j - 1] == false)
            dfs(i, j - 1, v, vis, st);
    if (!(t & (1 << 2)))
        if ((!(v[i][j + 1] & (1))) && vis[i][j + 1] == false)
            dfs(i, j + 1, v, vis, st);
    if (!(t & (1 << 1)))
        if ((!(v[i + 1][j] & (1 << 3))) && vis[i + 1][j] == false)
            dfs(i + 1, j, v, vis, st);
    if (!(t & (1 << 3)))
        if ((!(v[i - 1][j] & (1 << 1))) && vis[i - 1][j] == false)
            dfs(i - 1, j, v, vis, st);
}
void solve(void)
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    for (auto &i : v)
        for (auto &j : i)
            cin >> j;
    priority_queue<int> pq;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (vis[i][j])
                continue;
            int st = 0;
            dfs(i, j, v, vis, st);
            pq.push(st);
        }
    while (pq.size())
    {
        cout << pq.top() << ' ';
        pq.pop();
    }
}
//-----------------------------------------------------------------------------------------
signed main()
{
    // cout << fixed << showpoint << setprecision(10);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1, T;
    // cin >> test;
    for (T = 1; T <= test; T++)
    {
        // cout << "Case " << T << ": ";
        solve();
    }
    return 0;
}