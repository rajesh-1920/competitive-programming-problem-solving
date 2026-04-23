// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  19.10.2025

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
const int inf = 9e16 + 7;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;
//------------------------------(solve)----------------------------------------------------
int dp[111][3];
int ok(int n, int is, int &k, int &d)
{
    if (n == 0)
        return is;
    if (dp[n][is] >= 0)
        return dp[n][is];
    int ans = 0;
    for (int i = 1; i <= k; i++)
        if (n - i >= 0)
            ans += ok(n - i, (i >= d) ? 1 : is, k, d) % MOD;
    return dp[n][is] = ans;
}
void solve(void)
{
    int n, k, d;
    memset(dp, -1, sizeof dp);
    cin >> n >> k >> d;
    int ans = 0;
    for (int i = 1; i <= k; i++)
        if (n - i >= 0)
            ans += ok(n - i, (i >= d), k, d) % MOD;
    cout << (ans % MOD + MOD) % MOD << '\n';
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