// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  10.03.2025

#include <bits/stdc++.h>
using namespace std;
//----------------------------(definition section)-----------------------------------------
#define dbg(x) cout << #x << " = " << x << '\n'
#define int long int
#define fi first
#define sc second

#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()

const double eps = 1e-1;
const int inf = 9e16 + 7;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;
//-----------------------------------------------------------------------------------------
int dp[N][2][2][2];
int ok(int n, int ca, int cb, int cc, vector<int> &a, vector<int> &b, vector<int> &c)
{
    if (n == 0)
        return 0;
    if (dp[n][ca][cb][cc] != -1)
        return dp[n][ca][cb][cc];
    int ans = 0;
    if (ca < 1)
        ans = max(ans, ok(n - 1, 1, 0, 0, a, b, c) + a[n]);
    if (cb < 1)
        ans = max(ans, ok(n - 1, 0, 1, 0, a, b, c) + b[n]);
    if (cc < 1)
        ans = max(ans, ok(n - 1, 0, 0, 1, a, b, c) + c[n]);
    return dp[n][ca][cb][cc] = ans;
}
void solve(void)
{
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1), c(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> b[i] >> c[i];
    cout << ok(n, 0, 0, 0, a, b, c);
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