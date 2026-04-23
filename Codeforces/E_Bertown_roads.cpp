// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  28.08.2025

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

void dfs(int n, int &t, vector<int> g[], vector<int> &vis, set<pair<int, int>> &st, vector<int> &intime, vector<pair<int, int>> &ans)
{
    vis[n] = 1;
    intime[n] = t;
    t++;
    for (auto it : g[n])
    {
        if (vis[it])
            continue;
        st.erase({min(n, it), max(n, it)});
        ans.push_back({n, it});
        dfs(it, t, g, vis, st, intime, ans);
    }
}
void dfs1(int n, stack<int> &stc, vector<int> g[], vector<int> &vis)
{
    vis[n] = 1;
    for (auto it : g[n])
    {
        if (!vis[it])
            dfs1(it, stc, g, vis);
    }
    stc.push(n);
}
void solve(void)
{
    int n, m;
    cin >> n >> m;
    vector<int> g[n + 5], vis(n + 5, 0), intime(n + 5, 0);
    set<pair<int, int>> st;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        st.insert({min(x, y), max(x, y)});
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int t = 0;
    vector<pair<int, int>> ans;
    dfs(1, t, g, vis, st, intime, ans);
    for (auto it : st)
    {
        if (intime[it.fi] > intime[it.sc])
            ans.push_back({it.fi, it.sc});
        else
            ans.push_back({it.sc, it.fi});
    }
    vector<int> dic[n + 5], rev[n + 5], vi1(n + 5, 0), vi2(n + 5, 0);
    for (auto it : ans)
    {
        dic[it.fi].push_back(it.sc);
        rev[it.sc].push_back(it.fi);
    }
    stack<int> stc, tttt;
    for (int i = 1; i <= n; i++)
    {
        if (!vi1[i])
            dfs1(i, stc, dic, vi1);
    }
    int cnt = 0;
    while (!stc.empty())
    {
        int x = stc.top();
        stc.pop();
        if (!vi2[x])
        {
            cnt++;
            dfs1(x, tttt, rev, vi2);
        }
        if (cnt > 1)
        {
            cout << 0 << '\n';
            return;
        }
    }
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
    // cin >> test;
    for (T = 1; T <= test; T++)
    {
        // cout << "Case " << T << ": ";
        solve();
    }
    return 0;
}