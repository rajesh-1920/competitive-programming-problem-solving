// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  16.06.2025

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
const int N = 2e5 + 10;
//-----------------------------------------------------------------------------------------
int dp[N][2];
int ok(int n, int fl, vector<int> &v)
{
    if (n == v.size())
        return 0;
    if (dp[n][fl] != -inf)
        return dp[n][fl];
    int ans = -inf;
    if (fl == 0)
    {
        ans = max(ans, (ok(n + 1, 0, v)) + v[n]);
        if (n + 1 < v.size())
            ans = max(ans, (ok(n + 1, 1, v)) - v[n]);
    }
    else
    {
        ans = max(ans, (ok(n + 1, 0, v)) - v[n]);
        if (n + 1 < v.size())
            ans = max(ans, (ok(n + 1, 1, v)) + v[n]);
    }
    // cout << n << ' ' << ans << '\n';
    return dp[n][fl] = ans;
}
void solve(void)
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        dp[i][0] = dp[i][1] = -inf;
    }
    cout << ok(0, 0, v) << '\n';
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