// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  17.02.2026

#include <bits/stdc++.h>
using namespace std;
//----------------------------(definition section)-----------------------------------------
#define dbg(x) cout << #x << " = " << x << '\n'
#define fi first
#define sc second
#define int long long int

#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()

const double eps = 1e-1;
const int MOD = 1e9 + 7;
const int N = 1e7 + 1;
//-----------------------------------------------------------------------------------------
void dfs(int n, vector<int> &vis, map<int, int> &mp, vector<int> &v, vector<vector<int>> &g)
{
    vis[n] = 1;
    mp[v[n]]++;
    for (auto &it : g[n])
        if (!vis[it])
            dfs(it, vis, mp, v, g);
}
void solve(void)
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> v(n), vis(n, 0);
    for (auto &it : v)
        cin >> it;
    vector<vector<int>> g(n);
    for (int i = 0, x, y; i < m; i++)
    {
        cin >> x >> y;
        g[x - 1].push_back(y - 1), g[y - 1].push_back(x - 1);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        if (!vis[i])
        {
            map<int, int> mp;
            dfs(i, vis, mp, v, g);
            int s = 0, mx = 0;
            for (auto &it : mp)
                s += it.sc, mx = max(mx, it.sc);
            ans += (s - mx);
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