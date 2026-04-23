// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  17.10.2025

#include <bits/stdc++.h>
using namespace std;
//----------------------------(definition section)-----------------------------------------
#define dbg(x) cout << #x << " = " << x << '\n';
#define int long long int
#define fi first
#define sc second

#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()

const double eps = 1e-1;
const int inf = 2e18 + 7;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;
//------------------------------(solve)----------------------------------------------------
int rangeBitwiseAnd(int n, int m)
{
    int shift = 0;
    while (n < m)
    {
        n >>= 1;
        m >>= 1;
        shift++;
    }
    return n << shift;
}
void solve(void)
{
    int n, x;
    cin >> n >> x;
    int ans = -1;
    int l = n, r = inf;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        int t = rangeBitwiseAnd(n, m);
        if (t == x)
            r = m - 1, ans = m;
        else if (t < x)
            r = m - 1;
        else
            l = m + 1;
    }
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