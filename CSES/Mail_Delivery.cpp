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
void dfs(int n, vector<vector<pair<int, int>>> &v, vector<int> &mark, vector<int> &ans)
{
    while (!v[n].empty())
    {
        auto it = v[n].back();
        v[n].pop_back();
        if (!mark[it.sc])
        {
            mark[it.sc] = 1;
            dfs(it.fi, v, mark, ans);
        }
    }
    ans.push_back(n);
}
void solve(void)
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> v(n + 1);
    vector<int> deg(n + 1, 0), mark(m, 0), ans;
    for (int i = 0, x, y; i < m; i++)
    {
        cin >> x >> y;
        deg[x]++, deg[y]++;
        v[x].push_back({y, i});
        v[y].push_back({x, i});
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        if (deg[i] & 1)
            if (cnt)
            {
                cout << "IMPOSSIBLE\n";
                return;
            }
            else
                cnt++;
    dfs(1, v, mark, ans);
    if (ans.size() != m + 1)
        cout << "IMPOSSIBLE\n";
    else
        for (auto it : ans)
            cout << it << ' ';
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