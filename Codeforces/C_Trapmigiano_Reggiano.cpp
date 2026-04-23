// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  28.02.2025

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
//-----------------------------------------------------------------------------------------
void solve(void)
{
    int n, st, en;
    cin >> n >> st >> en;
    vector<vector<int>> gh(n + 1);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        gh[u].push_back(v);
        gh[v].push_back(u);
    }
    vector<int> dpt(n + 1, 0), vis(n + 1, 0);

    queue<int> q;
    q.push(en);
    vis[en] = 1;
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        for (auto it : gh[t])
        {
            if (vis[it])
                continue;
            dpt[it] += dpt[t] + 1;
            vis[it] = 1;
            q.push(it);
        }
    }
    vector<pair<int, int>> ans;
    for (int i = 1; i <= n; i++)
        ans.push_back({dpt[i], i});
    sort(rall(ans));
    for (auto it : ans)
        cout << it.sc << ' ';
    cout << '\n';
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