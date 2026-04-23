// Author:  Rajesh Biswas
// CF    :  rajesh_1920
// Date  :  15.01.2026

#include <bits/stdc++.h>
using namespace std;
//----------------------------(definition section)-----------------------------------------
#define dbg(x) cout << #x << " = " << x << '\n';
#define int long int
#define fi first
#define sc second

#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()

const double eps = 1e-1;
const int inf = 9e16 + 7;
const int MOD = 1e8;
const int N = 1e5 + 10;
//------------------------------(solve)----------------------------------------------------
struct stc
{
    int mx = 0, val = -1;
    map<int, int> mp;
};
void dfs(int n, int pr, int mx, vector<int> &par, vector<int> &lev, vector<vector<int>> &v)
{
    par[n] = pr;
    for (auto &it : v[n])
    {
        if (it == pr)
            continue;
        lev[it] = lev[n] + 1;
        mx = max(mx, lev[it]);
        dfs(it, n, mx, par, lev, v);
    }
}
void solve(void)
{
    int n, mx = 1;
    cin >> n;
    vector<int> col(n + 1), par(n + 1), lev(n + 1, 1);
    for (int i = 1; i <= n; i++)
        cin >> col[i];
    vector<vector<int>> v(n + 1);
    for (int i = 1, x, y; i < n; i++)
    {
        cin >> x >> y;
        v[x].push_back(y), v[y].push_back(x);
    }
    dfs(1, -1, mx, par, lev, v);
    vector<stc> store(n + 1);
    vector<vector<int>> lev_node(mx + 5);
    for (int i = 1; i <= n; i++)
        lev_node[lev[i]].push_back(i);
    for (int i = mx; i >= 1; i--)
    {
        for (auto &it : lev_node[i])
        {
            store[it].mp[col[it]]++;
            for (auto &ii : store[it].mp)
                store[par[ii.fi]].mp[ii.sc]++;
        }
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