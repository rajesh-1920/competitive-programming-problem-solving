// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  13.11.2025

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
const int inf = 1e18 + 7;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;
//------------------------------(solve)----------------------------------------------------
int ok(int tt, int &t, vector<int> &v)
{
    int s = 0;
    for (auto it : v)
    {
        s += tt / it;
        if (s >= t)
            return t;
    }
    return s;
}
void solve(void)
{
    int n, t;
    cin >> n >> t;
    vector<int> v(n);
    for (auto &it : v)
        cin >> it;
    int l = 0, r = inf, ans;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (ok(m, t, v) >= t)
            ans = m, r = m - 1;
        else
            l = m + 1;
    }r
    cout << ans << '\n';
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