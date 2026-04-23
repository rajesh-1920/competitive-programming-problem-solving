// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  14.01.2025

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
//----------------------------(definition section)-----------------------------------------
#define dbg(x) cout << #x << " = " << x << '\n'
#define fi first
#define sc second

#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()

const double eps = 1e-1;
const ll inf = 9e15 + 7;
const ll MOD = 1e9 + 7;
const ll N = 2e3 + 10;
//-----------------------------------------------------------------------------------------
vector<ll> g[N], vis(N, 0), depth(N, 0);

void dfs(ll n)
{
    vis[n] = 1;
    // dbg(n);
    for (auto it : g[n])
    {
        if (!vis[it])
        {
            depth[it] = depth[n] + 1;
            dfs(it);
        }
    }
}
void solve(void)
{
    ll n;
    cin >> n;
    vector<ll> t;
    for (ll i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        if (x == -1)
            t.push_back(i);
        else
            g[x].push_back(i);
    }
    for (auto it : t)
        if (vis[it] == 0)
            dfs(it);

    ll ss = 0;
    for (ll i = 1; i <= n; i++)
        ss = max(ss, depth[i]);
    cout << (ss + 1) << '\n';
}
//-----------------------------------------------------------------------------------------
int main()
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