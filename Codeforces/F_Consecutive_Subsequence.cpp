// Author:  Rajesh Biswas
// CF    :  rajesh_1920
// Date  :  02.01.2026

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
void dfs(int n, vector<int> &vis, vector<int> &ch, vector<int> &depth, vector<vector<int>> &v)
{
    vis[n] = 1;
    for (auto it : v[n])
        if (!vis[it])
        {
            dfs(it, vis, ch, depth, v);
            if (depth[n] < depth[it] + 1)
                depth[n] = depth[it] + 1, ch[n] = it;
        }
}
void solve(void)
{
    int n;
    cin >> n;
    vector<vector<int>> v(n + 1);
    map<int, int> mp;
    for (int i = 1, x; i <= n; i++)
    {
        cin >> x;
        if (mp.find(x) == mp.end())
            mp[x] = i;
        auto it = mp.lower_bound(x);
        if (it != mp.begin())
        {
            it--;
            if ((*it).fi == x - 1)
                v[(*it).sc].push_back(i);
        }
    }
    vector<int> ans, vis(n + 1, 0), ch(n + 1, 0), depth(n + 1, 0);
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            dfs(i, vis, ch, depth, v);
    // for (auto it : depth)
    //     cout << it << ' ';
    // cout << '\n';
    // for (auto it : ch)
    //     cout << it << ' ';
    // cout << '\n';

    int mx = 0, pp = 1;
    for (int i = 1; i <= n; i++)
    {
        if (depth[i] > mx)
            mx = depth[i], pp = i;
    }
    while (pp)
    {
        ans.push_back(pp);
        pp = ch[pp];
    }
    cout << ans.size() << '\n';
    for (auto it : ans)
        cout << it << ' ';
    cout << '\n';
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