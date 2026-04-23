// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  11.09.2025

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
void dfs(int n, int pr, vector<int> v[], vector<int> &sz, vector<int> &depth)
{
    for (auto it : v[n])
    {
        if (it == pr)
            continue;
        depth[it] = depth[n] + 1;
        dfs(it, n, v, sz, depth);
        sz[n] += sz[it] + 1;
    }
}
void dfs1(int n, int pr, vector<int> v[], vector<int> &ans)
{
    for (auto it : v[n])
    {
        if (it == pr)
            continue;
        dfs1(it, n, v, ans);
        ans[n] += ans[it];
    }
}
void solve(void)
{
    int n, k;
    cin >> n >> k;
    vector<int> v[n + 5], sz(n + 5, 0), depth(n + 5, 0);
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1, -1, v, sz, depth);
    priority_queue<pair<int, pair<int, int>>> pq;
    for (int i = 1; i <= n; i++)
        pq.push({-sz[i], {depth[i], i}});
    vector<int> ans(n + 5, 0);
    set<int> st;
    priority_queue<pair<int, int>> pp;
    while (k--)
    {
        ans[pq.top().sc.sc] = 1;
        st.insert(pq.top().sc.sc);
        pp.push({-depth[pq.top().sc.sc], pq.top().sc.sc});
        pq.pop();
    }
    dfs1(1, -1, v, ans);
    int an = 0;
    for (int i = 1; i <= n; i++)
        if (st.find(i) == st.end())
            an += ans[i];
    int mx = an;
    while (pq.size())
    {
        int t = pp.top().sc;
        int x = pq.top().sc.sc;
        pp.pop();
        pq.pop();
        pp.push({-depth[x], x});
        an -= depth[t];
        an += depth[x];
        an -= sz[x];
        mx = max(mx, an);
    }
    cout << mx << '\n';
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