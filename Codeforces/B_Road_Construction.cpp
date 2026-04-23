// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  16.01.2025

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
void solve(void)
{
    ll n, m;
    cin >> n >> m;
    map<ll, ll> mp;
    m += m;
    while (m--)
    {
        ll x;
        cin >> x;
        mp[x]++;
    }
    cout << n - 1 << '\n';
    ll t;
    for (ll i = 1; i <= n; i++)
        if (mp.find(i) == mp.end())
        {
            t = i;
            break;
        }
    for (ll i = 1; i <= n; i++)
    {
        if (t == i)
            continue;
        cout << t << ' ' << i << '\n';
    }
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