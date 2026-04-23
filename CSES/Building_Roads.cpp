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
void dfs(int n, vector<vector<int>> &g, vector<int> &vis)
{
    vis[n] = 1;
    for (auto it : g[n])
        if (!vis[it])
            dfs(it, g, vis);
}
void solve(void)
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<int> vis(n + 1, 0), ans;
    dfs(1, g, vis);
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            dfs(i, g, vis), ans.push_back(i);
    cout << ans.size() << '\n';
    for (auto it : ans)
        cout << 1 << ' ' << it << '\n';
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