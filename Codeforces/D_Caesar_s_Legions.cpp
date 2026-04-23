// Author:  Rajesh Biswas
// CF    :  rajesh_1920
// Date  :  14.01.2026

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
const int MOD = 1e8;
const int N = 1e5 + 10;
//------------------------------(solve)----------------------------------------------------
int dp[110][110][15][15];
int ok(int n1, int n2, int k1, int k2, int &tk1, int &tk2)
{
    if (n1 == 0 && n2 == 0)
        return 1;
    if (dp[n1][n2][k1][k2] != -1)
        return dp[n1][n2][k1][k2];
    int ans = 0;
    if (n1 > 0 && k1 > 0)
        ans = (ans + ok(n1 - 1, n2, k1 - 1, tk2, tk1, tk2)) % MOD;
    if (n2 > 0 && k2 > 0)
        ans = (ans + ok(n1, n2 - 1, tk1, k2 - 1, tk1, tk2)) % MOD;
    return dp[n1][n2][k1][k2] = ans;
}
void solve(void)
{
    int n1, n2, k1, k2;
    cin >> n1 >> n2 >> k1 >> k2;
    memset(dp, -1, sizeof(dp));
    cout << ok(n1, n2, k1, k2, k1, k2) % MOD;
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