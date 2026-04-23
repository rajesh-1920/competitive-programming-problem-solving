// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  28.01.2025

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
const ll inf = 9e16 + 7;
const ll MOD = 1e9 + 7;
const ll N = 1e5 + 10;
//-----------------------------------------------------------------------------------------
void solve(void)
{
    ll n, mn1, mx1, mn2, mx2, mn3, mx3;
    cin >> n >> mn1 >> mx1 >> mn2 >> mx2 >> mn3 >> mx3;
    ll c = mn3;
    n -= mn3;
    ll b = mn2;
    n -= mn2;
    ll a = mn1;
    n -= mn1;
    ll t = mx1 - mn1;
    if (n >= t)
    {
        a += t;
        n -= t;
    }
    else
    {
        a += n;
        n = 0;
    }
    t = mx2 - mn2;
    if (n >= t)
    {
        b += t;
        n -= t;
    }
    else
    {
        b += n;
        n = 0;
    }
    t = mx3 - mn3;
    if (n >= t)
    {
        c += t;
        n -= t;
    }
    else
    {
        c += n;
        n = 0;
    }

    cout << a << ' ' << b << ' ' << c;
}
//-----------------------------------------------------------------------------------------
int main()
{
    // cout << fixed << showpoint << setprecision(10);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1, T;
    //cin >> test;
    for (T = 1; T <= test; T++)
    {
        // cout << "Case " << T << ": ";
        solve();
    }
    return 0;
}