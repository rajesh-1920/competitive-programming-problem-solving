// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  08.03.2025

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
int dp[N][3];
int ok(int n, int pre, vector<int> &r, vector<int> &g, vector<int> &b)
{
    if (n == 0)
        return 0;
    if (dp[n][pre] != -1)
        return dp[n][pre];
    int ans = inf;
    if (pre == 0)
    {
        ans = min(ans, ok(n - 1, 1, r, g, b) + g[n]);
        ans = min(ans, ok(n - 1, 2, r, g, b) + b[n]);
    }
    if (pre == 1)
    {
        ans = min(ans, ok(n - 1, 0, r, g, b) + r[n]);
        ans = min(ans, ok(n - 1, 2, r, g, b) + b[n]);
    }
    if (pre == 2)
    {
        ans = min(ans, ok(n - 1, 1, r, g, b) + g[n]);
        ans = min(ans, ok(n - 1, 0, r, g, b) + r[n]);
    }
    return dp[n][pre] = ans;
}
void solve(void)
{
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    vector<int> r(n + 1), g(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> r[i] >> g[i] >> b[i];
    int ans = ok(n, 0, r, g, b);
    ans = min(ans, ok(n, 1, r, g, b));
    ans = min(ans, ok(n, 2, r, g, b));
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
        cout << "Case " << T << ": ";
        solve();
    }
    return 0;
}