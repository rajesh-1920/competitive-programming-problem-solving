// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  19.01.2025

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
const ll N = 1e3 + 10;
//-----------------------------------------------------------------------------------------
vector<ll> g[N], topo, vis(N);
void dfs(ll n)
{
    vis[n] = 1;
    for (auto it : g[n])
    {
        if (vis[it] == 0)
            dfs(it);
    }
    topo.push_back(n);
}
void solve(void)
{
    ll n;
    cin >> n;
    for (ll i = 1; i <= n; i++)
        vis[i] = 0;
    for (ll i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        for (ll j = 0; j < n; j++)
        {
            if (s[j] == '1' && i < j + 1)
                g[i].push_back(j + 1);
        }
    }
    for (ll i = 1; i <= n; i++)
        if (vis[i] == 0)
            dfs(i);
    reverse(all(topo));
    for (auto it : topo)
        cout << it << ' ';
    cout << '\n';
    topo.clear();
    for (ll i = 1; i <= n; i++)
    {
        g[i].push_back(1);
        g[i].clear();
    }
}
//-----------------------------------------------------------------------------------------
int main()
{
    // cout << fixed << showpoint << setprecision(10);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1, T;
    cin >> test;
    for (T = 1; T <= test; T++)
    {
        // cout << "Case " << T << ": ";
        solve();
    }
    return 0;
}