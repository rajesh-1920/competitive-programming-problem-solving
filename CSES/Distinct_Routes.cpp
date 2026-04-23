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
void dfs(int n, vector<int> &par, vector<int> &vis, vector<multiset<int>> &v)
{
    vis[n] = 1;
    for (auto it : v[n])
    {
        if (vis[it])
            continue;
        par[it] = n;
        dfs(it, par, vis, v);
    }
}
void solve(void)
{
    int n, m;
    cin >> n >> m;
    vector<multiset<int>> v(n + 1);
    for (int i = 0, x, y; i < m; i++)
    {
        cin >> x >> y;
        v[x].insert(y);
    }
    vector<vector<int>> ans;
    while (true)
    {
        vector<int> vis(n + 1, 0), par(n + 1, -1), temp;
        dfs(1, par, vis, v);
        if (par[n] == -1)
            break;
        int t = n;
        while (t != -1)
        {
            temp.push_back(t);
            t = par[t];
        }
        reverse(all(temp));
        ans.push_back(temp);
        for (int i = 1; i < temp.size(); i++)
            v[temp[i - 1]].erase(v[temp[i - 1]].find(temp[i]));
    }
    cout << ans.size() << '\n';
    for (auto it : ans)
    {
        cout << it.size() << '\n';
        for (auto ii : it)
            cout << ii << ' ';
        cout << '\n';
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