// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  13.11.2025

#include <bits/stdc++.h>
using namespace std;
//----------------------------(definition section)-----------------------------------------
#define dbg(x) cout << #x << " = " << x << '\n';
#define int long long int
#define fi first
#define sc second

#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()

const double eps = 1e-1;
const int inf = 9e16 + 7;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;
//------------------------------(solve)----------------------------------------------------
void dfs(int i, int j, int &n, int &m, vector<string> &s)
{
    s[i][j] = '#';
    if (i + 1 < n && s[i + 1][j] == '.')
        dfs(i + 1, j, n, m, s);
    if (i - 1 >= 0 && s[i - 1][j] == '.')
        dfs(i - 1, j, n, m, s);
    if (i + 1 < n && s[i + 1][j] == '.')
        dfs(i + 1, j, n, m, s);
    if (j - 1 >= 0 && s[i][j - 1] == '.')
        dfs(i, j - 1, n, m, s);
    if (j + 1 < m && s[i][j + 1] == '.')
        dfs(i, j + 1, n, m, s);
}
void solve(void)
{
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (auto &it : s)
        cin >> it;
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (s[i][j] == '.' && !vis[i][j])
            {
                ans++;
                dfs(i, j, n, m, s);
            }
    cout << ans << '\n';
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