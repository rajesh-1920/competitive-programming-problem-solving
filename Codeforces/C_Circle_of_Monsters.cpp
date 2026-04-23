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
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;
//------------------------------(solve)----------------------------------------------------
int ok(int i, int fl, vector<pair<int, int>> &v, vector<vector<int>> &dp)
{
    if (i == v.size())
        return (fl == 0 ? inf : 0);
    if (dp[i][fl] != -1)
        return dp[i][fl];
    int ans = inf;
    if (fl)
        ans = ok(i + 1, fl, v, dp) + (max(0LL, (v[i].fi - v[i].sc)));
    else
    {
        ans = ok(i + 1, 0, v, dp) + (max(0LL, (v[i].fi - v[i].sc)));
        ans = min(ans, ok(i + 1, 1, v, dp) + v[i].fi);
    }
    return dp[i][fl] = ans;
}
void solve(void)
{
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    vector<vector<int>> dp(2 * n + 10, vector<int>(5, -1));
    for (auto &it : v)
        cin >> it.fi >> it.sc;
    for (int i = 0; i < n; i++)
        v.push_back({v[i].fi, v[i].sc});
    int ans = ok(0, 0, v, dp);
    ans - min(ans, ok(0, 1, v, dp) + v[0].fi);
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
        // cout << "Case " << T << ": ";
        solve();
    }
    return 0;
}