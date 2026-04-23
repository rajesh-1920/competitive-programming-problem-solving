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

void dfs1(int n, vector<int> g[], vector<int> &vis, stack<int> &st)
{
    vis[n] = 1;
    for (auto it : g[n])
        if (!vis[it])
            dfs1(it, g, vis, st);
    st.push(n);
}

void dfs2(int n, vector<int> gt[], vector<int> &vis, int &cnt)
{
    vis[n] = 1;
    cnt++;
    for (auto it : gt[n])
        if (!vis[it])
            dfs2(it, gt, vis, cnt);
}

void solve(void)
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> g[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    vector<int> vis(n + 1, 0);
    stack<int> st;
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            dfs1(i, g, vis, st);

    vector<int> gt[n + 1];
    for (int i = 1; i <= n; i++)
    {
        vis[i] = 0;
        for (int v : g[i])
            gt[v].push_back(i);
    }
    vector<int> ans;
    while (!st.empty())
    {
        int n = st.top();
        st.pop();
        if (!vis[n])
        {
            int cnt = 0;
            dfs2(n, gt, vis, cnt);
            ans.push_back(cnt);
        }
    }
    // sort(rall(ans));
    for (auto it : ans)
        cout << it << " ";
    int sum = 0;
    for (int i = 0; i < k && i < ans.size(); i++)
        sum += ans[i];
    cout << sum << '\n';
}

//-----------------------------------------------------------------------------------------
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1, T;
    cin >> test;
    for (T = 1; T <= test; T++)
    {
        solve();
    }
    return 0;
}
