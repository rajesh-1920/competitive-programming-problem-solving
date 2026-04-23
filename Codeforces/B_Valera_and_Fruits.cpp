// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  23.01.2025

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
    ll n, v;
    cin >> n >> v;
    map<ll, ll> mp;
    while (n--)
    {
        ll a, b;
        cin >> a >> b;
        mp[a] += b;
    }
    ll ans = 0;
    if (mp[1] <= v)
    {
        ans += mp[1];
        mp[1] = 0;
    }
    else
    {
        ans += v;
        mp[1] -= v;
    }
    for (ll i = 2; i <= 3010; i++)
    {
        ll t = v;
        if (mp[i - 1] <= t)
        {
            ans += mp[i - 1];
            t -= mp[i - 1];
            mp[i - 1] = 0;
        }
        else
        {
            ans += t;
            mp[i - 1] -= t;
            t = 0;
        }
        if (mp[i] <= t)
        {
            ans += mp[i];
            t -= mp[i];
            mp[i] = 0;
        }
        else
        {
            ans += t;
            mp[i] -= t;
            t = 0;
        }
        //dbg(i);
        //dbg(ans);
    }
    cout << ans << '\n';
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