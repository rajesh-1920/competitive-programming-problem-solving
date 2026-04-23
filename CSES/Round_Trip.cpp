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
void dfs(int n, int pr, int &st, int &en, vector<vector<int>> &v,
         vector<int> &par, vector<int> &vis)
{
    vis[n] = 1;
    if (st != -1)
        return;
    for (auto it : v[n])
    {
        if (st != -1)
            return;
        if (it == pr)
            continue;
        if (vis[it])
        {
            st = it;
            en = n;
            return;
        }
        else
        {
            par[it] = n;
            dfs(it, n, st, en, v, par, vis);
        }
    }
}
void solve(void)
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n + 1);
    for (int i = 0, x, y; i < m; i++)
    {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    vector<int> vis(n + 1, 0), par(n + 1, -1);
    int st = -1, en = -1;
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            dfs(i, -1, st, en, v, par, vis);
    if (st == -1)
        cout << "IMPOSSIBLE\n";
    else
    {
        vector<int> ans = {st};
        while (en != st)
        {
            ans.push_back(en);
            en = par[en];
        }
        ans.push_back(st);
        cout << ans.size() << '\n';
        for (auto it : ans)
            cout << it << ' ';
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