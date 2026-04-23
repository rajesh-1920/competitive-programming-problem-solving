// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  19.10.2025

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
const int N = 2e5 + 10;
//------------------------------(solve)----------------------------------------------------
void dfs(int n, int &fl, vector<int> &vis, vector<vector<int>> &v)
{
    vis[n] = 1;
    if (fl)
        return;
    for (auto it : v[n])
    {
        if (vis[it] == 1)
            fl = 1;
        if (fl)
            return;
        if (!vis[it])
            dfs(it, fl, vis, v);
    }
    vis[n] = 2;
}
void solve(void)
{
    int n, k;
    cin >> n >> k;
    // dbg(n);
    vector<vector<int>> v(n + 1);
    while (k--)
    {
        vector<int> temp(n);
        for (auto &it : temp)
            cin >> it;
        for (int i = 2; i < n; i++)
            v[temp[i - 1]].push_back(temp[i]);
    }
    vector<int> vis(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        int fl = 0;
        if (!vis[i])
            dfs(i, fl, vis, v);
        if (fl)
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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