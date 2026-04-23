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
void dfs(int n, vector<int> &vis, vector<int> &tops, vector<vector<int>> &g)
{
    vis[n] = 1;
    for (auto it : g[n])
        if (!vis[it])
            dfs(it, vis, tops, g);
    tops.push_back(n);
}
void solve(void)
{
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    for (int i = 1, u, v, x, y; i < n; i++)
    {
        cin >> u >> v >> x >> y;
        if (x > y)
            g[u].push_back(v);
        else
            g[v].push_back(u);
    }
    vector<int> ans, vis(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
            dfs(i, vis, ans, g);
    }
    reverse(all(ans));
    for (auto it : ans)
        cout << it << ' ';
    cout << '\n';
}
//-----------------------------------------------------------------------------------------
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