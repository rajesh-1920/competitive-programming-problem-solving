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
int ok(int n, int fl, vector<int> &v, vector<vector<int>> &dp)
{
    if (n == v.size())
        return 0;
    if (dp[n][fl] != -1)
        return dp[n][fl];
    int ans = ok(n + 1, 0, v, dp) + 1;
    if (v[n] == 1 && fl != 1)
        ans = min(ans, ok(n + 1, 1, v, dp));
    if (v[n] == 2 && fl != 2)
        ans = min(ans, ok(n + 1, 2, v, dp));
    if (v[n] == 3)
    {
        if (fl != 1)
            ans = min(ans, ok(n + 1, 1, v, dp));
        if (fl != 2)
            ans = min(ans, ok(n + 1, 2, v, dp));
    }
    return dp[n][fl] = ans;
}
void solve(void)
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &it : v)
        cin >> it;
    vector<vector<int>> dp(n, vector<int>(3, -1));
    cout << ok(0, 0, v, dp) << '\n';
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