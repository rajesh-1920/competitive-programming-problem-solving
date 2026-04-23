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
int ok(int n, int cnt, vector<vector<int>> &dp, const int &k, const int &z, const vector<int> &v)
{
    if (n < 0 || n + 2 * cnt > k)
        return 0;
    if (dp[n][cnt] > -1)
        return dp[n][cnt];
    int ans = ok(n + 1, cnt, dp, k, z, v) + v[n];
    if (cnt < z)
        ans = max(ans, ok(n - 1, cnt + 1, dp, k, z, v) + v[n]);
    return dp[n][cnt] = ans;
}
void solve(void)
{
    int n, k, z;
    cin >> n >> k >> z;
    vector<int> v(n);
    vector<vector<int>> dp(n, vector<int>(6, -1));
    for (auto &it : v)
        cin >> it;
    cout << ok(0, 0, dp, k, z, v) << '\n';
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