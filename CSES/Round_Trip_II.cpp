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
bool dfs(int n, int &st, int &en, vector<int> &vis, vector<int> &par, vector<vector<int>> &v)
{
    vis[n] = 1;
    for (auto it : v[n])
    {
        if (vis[it] == 1)
        {
            st = it;
            en = n;
            return true;
        }
        if (vis[it] == 0)
        {
            par[it] = n;
            if (dfs(it, st, en, vis, par, v))
                return true;
        }
    }
    vis[n] = 2;
    return false;
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
    }
    vector<int> vis(n + 1, 0), par(n + 1, -1);
    int st, en;
    for (int i = 1; i <= n; i++)
        if (!vis[i] && dfs(i, st, en, vis, par, v))
        {
            vector<int> ans = {st};
            while (true)
            {
                ans.push_back(en);
                en = par[en];
                if (en == st)
                    break;
            }
            ans.push_back(st);
            if (ans.size() > 2)
            {
                cout << ans.size() << '\n';
                reverse(all(ans));
                for (auto it : ans)
                    cout << it << ' ';
                return;
            }
        }
    cout << "IMPOSSIBLE\n";
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