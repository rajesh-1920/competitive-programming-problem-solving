// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  09.08.2025

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
const int N = 1e5 + 10;
//------------------------------(solve)----------------------------------------------------
void dfs(int n, map<int, vector<int>> &mp, map<int, int> &vis, map<int, int> &depth)
{
    vis[n] = 1;
    for (auto it : mp[n])
    {
        if (vis.find(n + it) == vis.end())
        {
            depth[n + it] = depth[n] + 1;
            dfs(n + it, mp, vis, depth);
        }
    }
}
void solve(void)
{
    int n;
    cin >> n;
    vector<int> v(n);
    map<int, vector<int>> mp;
    map<int, int> vis, depth;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        mp[v[i] + i].push_back(i);
    }
    depth[n] = 1;
    dfs(n, mp, vis, depth);
    cout << (*(--depth.end())).fi << '\n';
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