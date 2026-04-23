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
void dfs(int n, int pr, map<pair<int, int>, int> &mp, vector<vector<int>> &v)
{
    int cnt = 1;
    for (auto it : v[n])
    {
        if (mp[{min(pr, n), max(pr, n)}] == cnt)
            cnt++;
        if (it == pr)
            continue;
        mp[{min(it, n), max(it, n)}] = cnt;
        dfs(it, n, mp, v);
        cnt++;
    }
}
void solve(void)
{
    int n;
    cin >> n;
    vector<vector<int>> v(n + 1);
    vector<pair<int, int>> edg;
    for (int i = 1, x, y; i < n; i++)
    {
        cin >> x >> y;
        edg.push_back({x, y});
        v[x].push_back(y);
        v[y].push_back(x);
    }
    map<pair<int, int>, int> mp;
    dfs(1, 0, mp, v);
    int mx = 0;
    for (auto it : mp)
        mx = max(mx, it.sc);
    vector<vector<int>> ans(mx + 1);
    for (int i = 0; i < edg.size(); i++)
    {
        ans[mp[{min(edg[i].fi, edg[i].sc), max(edg[i].fi, edg[i].sc)}]].push_back(i + 1);
    }
    cout << mx << '\n';
    for (int i = 1; i <= mx; i++)
    {
        cout << ans[i].size() << ' ';
        for (auto it : ans[i])
            cout << it << ' ';
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