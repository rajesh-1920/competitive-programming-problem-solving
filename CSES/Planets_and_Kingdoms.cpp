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
void dfs(int n, vector<vector<int>> &g, vector<int> &topo, vector<int> &vis)
{
    vis[n] = 1;
    for (auto it : g[n])
        if (!vis[it])
            dfs(it, g, topo, vis);
    topo.push_back(n);
}
void solve(void)
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edge(m);
    for (auto &it : edge)
        cin >> it.fi >> it.sc;
    vector<vector<int>> g(n + 1), rg(n + 1);
    for (auto it : edge)
        g[it.fi].push_back(it.sc), rg[it.sc].push_back(it.fi);
    vector<int> topo, vis(n + 1, 0), rvis(n + 1, 0), ans(n + 1, -1);
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            dfs(i, g, topo, vis);
    int cnt = 0;
    while (!topo.empty())
    {
        int t = topo.back();
        topo.pop_back();
        if (rvis[t])
            continue;
        vector<int> temp;
        dfs(t, rg, temp, rvis);
        cnt++;
        for (auto it : temp)
            ans[it] = cnt;
    }
    cout << cnt << '\n';
    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
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