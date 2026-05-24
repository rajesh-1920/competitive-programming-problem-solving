// Author:  Rajesh Biswas
// CF    :  rajesh_1920
// Date  :  23.05.2026

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
int ok(int n, int fl, vector<int> &va, vector<int> &vb, vector<vector<int>> &dp)
{
    if (n == va.size())
        return 0;
    if (dp[n][fl] != -1)
        return dp[n][fl];
    int ans = ok(n + 1, 0, va, vb, dp);
    if (fl != 1)
        ans = max(ans, ok(n + 1, 1, va, vb, dp) + va[n]);
    if (fl != 2)
        ans = max(ans, ok(n + 1, 2, va, vb, dp) + vb[n]);
    return dp[n][fl] = ans;
}
void solve(void)
{
    int n;
    cin >> n;
    vector<int> va(n), vb(n);
    for (auto &it : va)
        cin >> it;
    for (auto &it : vb)
        cin >> it;
    vector<vector<int>> dp(n, vector<int>(3, -1));
    cout << ok(0, 0, va, vb, dp) << '\n';
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