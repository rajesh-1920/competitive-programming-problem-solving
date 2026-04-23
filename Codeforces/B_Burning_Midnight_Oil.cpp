// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  20.02.2026

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

void solve()
{
    int n, k;
    cin >> n >> k;
    int l = 0, r = inf, ans = inf;
    while (l <= r)
    {
        int v = (l + r) / 2, s = (l + r) / 2, x = k;
        while (v >= x)
        {
            s += (v / x);
            x *= k;
        }
        if (s >= n)
            ans = min(ans, v), r = v - 1;
        else
            l = v + 1;
    }
    cout << ans << '\n';
}

//-----------------------------(Suduko)----------------------------------------------------

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