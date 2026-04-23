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
void solve(void)
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n + 1);
    vector<int> par(n + 1, -1), vis(n + 1, 0);
    for (int i = 0, x, y; i < m; i++)
    {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    queue<int> q;
    q.push(1);
    vis[1] = 1;
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        for (auto it : v[t])
            if (!vis[it])
                vis[it] = 1, par[it] = t, q.push(it);
    }
    if (vis[n] == 0)
        cout << "IMPOSSIBLE\n";
    else
    {
        vector<int> ans;
        while (n != -1)
        {
            ans.push_back(n);
            n = par[n];
        }
        cout << ans.size() << '\n';
        reverse(all(ans));
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
