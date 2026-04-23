// Author:  Rajesh Biswas
// CF    :  rajesh_1920
// Date  :  18.01.2026

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
void dfs(int n, vector<int> &vis, stack<int> &st, vector<vector<int>> &v)
{
    vis[n] = 1;
    for (auto &it : v[n])
        if (!vis[it])
            dfs(it, vis, st, v);
    st.push(n);
}
void solve(void)
{
    int n, m;
    cin >> n;
    vector<int> cost(n), vis(n, 0), revis(n, 0);
    for (auto &it : cost)
        cin >> it;
    cin >> m;
    vector<vector<int>> v(n), rev(n);
    for (int i = 0, x, y; i < m; i++)
    {
        cin >> x >> y;
        v[x - 1].push_back(y - 1);
        rev[y - 1].push_back(x - 1);
    }
    stack<int> st;
    for (int i = 0; i < n; i++)
        if (!vis[i])
            dfs(i, vis, st, v);
    int ans = 0, cnt = 1;
    while (!st.empty())
    {
        int it = st.top();
        st.pop();
        if (!revis[it])
        {
            stack<int> temp;
            dfs(it, revis, temp, rev);
            map<int, int> mp;
            while (!temp.empty())
            {
                mp[cost[temp.top()]]++;
                temp.pop();
            }
            ans += (*mp.begin()).fi;
            cnt = (cnt * (*mp.begin()).sc) % MOD;
        }
    }
    cout << ans << ' ' << cnt << '\n';
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