// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  15.01.2025

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
const ll N = 1e5 + 10;
//-----------------------------------------------------------------------------------------
ll par[N];
ll parent(ll n)
{
    if (n == par[n])
        return n;
    return par[n] = parent(par[n]);
}
void uni(ll a, ll b)
{
    a = parent(a), b = parent(b);
    if (a != b)
        par[b] = a;
}
void solve(void)
{
    ll n, m, cnt = 0, pp = 0;
    cin >> n >> m;
    vector<ll> v[n + 5];
    for (ll i = 1; i <= n; i++)
        par[i] = i;
    // dbg(1);
    for (ll i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        if (x == 0)
            cnt++;
        for (ll ii = 0; ii < x; ii++)
        {
            ll t;
            cin >> t;
            v[i].push_back(t);
        }
        if (pp == 0 && x)
            pp = v[i][0];
        for (ll ii = 1; ii < x; ii++)
            uni(v[i][0], v[i][ii]);
    }
    pp = parent(pp);
    for (ll i = 1; i <= n; i++)
    {
        if (v[i].size())
        {
            ll t = v[i][0];
            t = parent(t);
            if (t != pp)
                cnt++;
            // dbg(pp);
            // dbg(t);
            uni(pp, t);
        }
    }
    cout << cnt << '\n';
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