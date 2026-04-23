// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  28.02.2025

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
const int N = 1e3 + 10;
//-----------------------------------------------------------------------------------------
vector<int> v(N);
int dp[N][5];
int ok(int n, int pre)
{
    if (n == 0)
        return 0;
    if (dp[n][pre] != -1)
        return dp[n][pre];
    int ans = inf;
    if (v[n] == 0)
        ans = min(ans, ok(n - 1, 0) + 1);
    else if (v[n] == 1)
    {
        if (pre == 1)
            ans = min(ans, ok(n - 1, 0) + 1);
        else
            ans = min(ans, ok(n - 1, 1));
    }
    else if (v[n] == 2)
    {
        if (pre == 2)
            ans = min(ans, ok(n - 1, 0) + 1);
        else
            ans = min(ans, ok(n - 1, 2));
    }
    else
    {
        if (pre != 1)
            ans = min(ans, ok(n - 1, 1));
        if (pre != 2)
            ans = min(ans, ok(n - 1, 2));
    }
    // cout << n << ' ' << ans << '\n';
    return dp[n][pre] = ans;
}
void solve(void)
{
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    cout << ok(n, 0);
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