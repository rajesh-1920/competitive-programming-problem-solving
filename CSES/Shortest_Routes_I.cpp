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
const int inf = 9e17 + 7;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;
//------------------------------(solve)----------------------------------------------------
void solve(void)
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n + 1);
    for (int i = 0, x, y, z; i < m; i++)
    {
        cin >> x >> y >> z;
        g[x].push_back({z, y});
        g[y].push_back({z, y});
    }
    vector<int> dis(n + 1, inf), vis(n + 1, 0);
    multiset<pair<int, int>> st;
    dis[1] = 0;
    st.insert({0, 1});
    while (st.size())
    {
        int nd = st.begin()->sc;
        st.erase(st.begin());
        if (vis[nd])
            continue;
        vis[nd] = 1;
        for (auto it : g[nd])
            if (dis[it.sc] > dis[nd] + it.fi)
                st.insert({dis[it.sc] = dis[nd] + it.fi, it.sc});
    }
    for (int i = 1; i <= n; i++)
        cout << dis[i] << ' ';
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