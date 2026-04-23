// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  17.10.2025

#include <bits/stdc++.h>
using namespace std;
//----------------------------(definition section)-----------------------------------------
#define dbg(x) cout << #x << " = " << x << '\n';
#define fi first
#define sc second

#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()

const double eps = 1e-1;
const int MOD = 1e9 + 7;
const int N = 5e5 + 10;
//------------------------------(solve)----------------------------------------------------
vector<int> g[N], topo, vis(N, 0);
int cycle = 0;
void dfs(int n)
{
    vis[n] = 1;
    for (auto it : g[n])
    {
        if (vis[it] == 1)
            cycle = 1;
        if (vis[it] == 0)
            dfs(it);
    }
    vis[n] = 2;
    topo.push_back(n);
}
void solve(void)
{
    int n;
    cin >> n;
    vector<int> v(n + 1);
    map<int, int> mp;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        mp[v[i]] = i;
        g[i].clear();
        vis[i] = 0;
    }
    int fl = 0;

    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (x == v[i])
            continue;
        if (mp.find(x) == mp.end() || x < v[i])
            fl = 1;
        else
            g[mp[x]].push_back(i);
    }
    if (fl)
    {
        cout << -1 << '\n';
        return;
    }
    cycle = 0;
    topo.clear();
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
            dfs(i);
    }
    if (cycle)
    {
        cout << -1 << '\n';
        return;
    }
    vector<pair<int, int>> ans;
    reverse(all(topo));
    for (auto it : topo)
        for (auto ii : g[it])
            ans.push_back({ii, it});
    reverse(all(ans));
    cout << ans.size() << '\n';
    for (auto it : ans)
        cout << it.fi << ' ' << it.sc << '\n';
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
        cout << "Case #" << T << ": ";
        solve();
    }
    return 0;
}