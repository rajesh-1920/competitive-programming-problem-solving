// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  10.03.2025

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
int dp[110][N];
int ok(int n, int wg, vector<int> &v, vector<int> &w)
{
    if (n == 0)
        return 0;
    if (dp[n][wg] != -1)
        return dp[n][wg];
    int ans = 0;
    ans = max(ans, ok(n - 1, wg, v, w));
    if (wg >= w[n])
        ans = max(ans, ok(n - 1, wg - w[n], v, w) + v[n]);
    return dp[n][wg] = ans;
}
void solve(void)
{
    memset(dp, -1, sizeof(dp));
    int n, wg;
    cin >> n >> wg;
    vector<int> v(n + 1), w(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> w[i] >> v[i];
    cout << ok(n, wg, v, w);
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