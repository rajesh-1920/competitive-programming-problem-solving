// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  11.04.2025

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
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;
//-----------------------------------------------------------------------------------------
void solve(void)
{
    int a, b;
    cin >> a >> b;
    int c = a + b;

    int aa = 0;
    while (a)
    {
        if (a % 10 > 0)
            aa = aa * 10 + (a % 10);
        a /= 10;
    }
    int bb = 0;
    while (b)
    {
        if (b % 10 > 0)
            bb = bb * 10 + (b % 10);
        b /= 10;
    }
    int cc = 0;
    while (c)
    {
        if (c % 10 > 0)
            cc = cc * 10 + (c % 10);
        c /= 10;
    }
    a = aa;
    b = bb;
    c = cc;
    aa = 0;
    while (a)
    {
        if (a % 10 > 0)
            aa = aa * 10 + (a % 10);
        a /= 10;
    }
    bb = 0;
    while (b)
    {
        if (b % 10 > 0)
            bb = bb * 10 + (b % 10);
        b /= 10;
    }
    cc = 0;
    while (c)
    {
        if (c % 10 > 0)
            cc = cc * 10 + (c % 10);
        c /= 10;
    }
    // dbg(aa);
    // dbg(bb);
    // dbg(cc);
    if (cc == (aa + bb))
        cout << "YES\n";
    else
        cout << "NO\n";
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