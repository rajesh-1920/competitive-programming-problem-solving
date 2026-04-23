// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  02.02.2025

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
const int MOD = 998244353;
const int N = 2e5 + 10;
//-----------------------------------------------------------------------------------------
vector<int> g[N], path(N, 0), vis(N, 0);
void dfs(int nd, int par = -1)
{
    vis[nd] = 1;
    for (auto it : g[nd])
    {
        if (vis[it])
        {
            if (it != par && it != 1)
                path[it] = (path[it] + 1) % MOD;
            continue;
        }
        path[it] = (path[nd] + 1) % MOD;
        dfs(it, nd);
    }
}
void solve(void)
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &it : v)
        cin >> it;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            int t = __gcd(v[i], v[j]);
            if (t != 1)
            {
                g[i + 1].push_back(j + 1);
                g[j + 1].push_back(i + 1);
            }
        }
    dfs(1);
    for (int i = 1; i <= n; i++)
    {
        cout << i << ' ' << path[i] << '\n';
    }
    cout << path[n];
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