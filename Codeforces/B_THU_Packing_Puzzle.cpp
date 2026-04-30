// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  30.04.2026

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
    int t, h, u, ans = 0;
    cin >> t >> h >> u;
    if (t >= u)
    {
        ans += 4 * u;
        t -= u;
        u = 0;
    }
    else
    {
        ans += 4 * t;
        u -= t;
        ans += 3 * u;
        t = u = 0;
    }
    if (t >= 2 * h)
    {
        ans += 7 * h;
        t -= 2 * h;
        h = 0;
    }
    else
    {
        int x = t / 2;
        ans += x * 7;
        h -= x;
        t -= 2 * x;
        if (t)
        {
            h--, t--;
            ans += 5;
        }
        ans += 3 * h;
    }
    if (t)
        ans += 3 + (t - 1) * 2;
    cout << ans << '\n';
}
//-----------------------------------------------------------------------------------------
signed main()
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