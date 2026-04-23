// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  20.02.2026

#include <bits/stdc++.h>
using namespace std;
//----------------------------(definition section)-----------------------------------------
#define dbg(x) cout << #x << " = " << x << '\n'
#define int long long int
#define fi first
#define sc second

#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()

const double eps = 1e-1;
const int inf = 9e16 + 7;
const int MOD = 1e9 + 7;
//----------------------------(solve section)-----------------------------------------------------
void dfs(int n, int par, vector<int> &vis, vector<int> &intime, vector<int> &low, int &cnt, set<int> &ans, vector<vector<pair<int, int>>> &v)
{
    vis[n] = 1, intime[n] = low[n] = cnt++;
    for (auto &it : v[n])
        if (it.fi == par)
            continue;
        else if (vis[it.fi])
            low[n] = min(low[n], intime[it.fi]);
        else
        {
            dfs(it.fi, n, vis, intime, low, cnt, ans, v);
            if (intime[n] < low[it.fi])
                ans.insert(it.sc);
            low[n] = min(low[n], low[it.fi]);
        }
}
void merge(int n, int &pr, vector<int> &vis, vector<int> &par, vector<vector<int>> &g)
{
    vis[n] = 1, par[n] = pr;
    for (auto &it : g[n])
        if (!vis[it])
            merge(it, pr, vis, par, g);
}
void diameter(int n, int pr, vector<int> &depth, vector<vector<int>> &g)
{
    for (auto &it : g[n])
        if (it != pr)
        {
            depth[it] = depth[n] + 1;
            diameter(it, n, depth, g);
        }
}
void solve()
{
    int n, m, cnt = 0;
    cin >> n >> m;
    vector<pair<int, int>> edge;
    vector<vector<pair<int, int>>> v(n + 1);
    for (int i = 0, x, y; i < m; i++)
    {
        cin >> x >> y;
        v[x].push_back({y, edge.size()}), v[y].push_back({x, edge.size()});
        edge.push_back({x, y});
    }
    vector<int> vis(n + 5, 0), intime(n + 5, 0), low(n + 5, 0), par(n + 5, -1), depth(n + 5, 0);
    set<int> st;
    dfs(1, 0, vis, intime, low, cnt, st, v);

    vector<vector<int>> g(n + 1), dia(n + 1);
    for (int i = 0; i < m; i++)
        if (st.find(i) == st.end())
            g[edge[i].fi].push_back(edge[i].sc), g[edge[i].sc].push_back(edge[i].fi);
    vis.assign(n + 5, 0LL);
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            merge(i, i, vis, par, g);

    for (auto &it : st)
        dia[par[edge[it].fi]].push_back(par[edge[it].sc]), dia[par[edge[it].sc]].push_back(par[edge[it].fi]);
    diameter(1, 0, depth, dia);
    cnt = 0, m = 1;
    for (int i = 1; i <= n; i++)
    {
        if (depth[i] > cnt)
            cnt = depth[i], m = i;
        depth[i] = 0;
    }
    diameter(m, 0, depth, dia);
    for (int i = 1; i <= n; i++)
        cnt = max(cnt, depth[i]);
    cout << cnt << '\n';
}
//-----------------------------(Suduko)----------------------------------------------------
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