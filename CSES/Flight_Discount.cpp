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
    vector<vector<pair<int, int>>> v(n + 1);
    map<pair<int, int>, int> mp;
    for (int i = 0, x, y, z; i < m; i++)
    {
        cin >> x >> y >> z;
        v[x].push_back({z, y});
        v[y].push_back({z, x});
        mp[{x, y}] = mp[{y, x}] = z;
    }
    multiset<pair<int, int>> st;
    vector<int> dis(n + 1, inf), vis(n + 1, 0), par(n + 1, -1);
    dis[1] = 0;
    st.insert({0, 1});
    while (!st.empty())
    {
        int nd = st.begin()->sc;
        st.erase(st.begin());
        if (vis[nd])
            continue;
        vis[nd] = 1;
        for (auto it : v[nd])
        {
            if (dis[it.sc] > dis[nd] + it.fi)
            {
                dis[it.sc] = dis[nd] + it.fi;
                par[it.sc] = nd;
                if (mp.find({it.sc, nd}) != mp.end())
                    mp[{it.sc, nd}] = mp[{nd, it.sc}] = min(mp[{nd, it.sc}], dis[it.sc]);
                st.insert({dis[it.sc], it.sc});
            }
        }
    }
    int pr = n, mx = 0;
    while (pr != -1)
    {
        mx = max(mx, mp[{pr, par[pr]}]);
        pr = par[pr];
    }
    cout << dis[n] - mx + (mx / 2) << '\n';
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