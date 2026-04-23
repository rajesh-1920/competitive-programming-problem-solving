// Author:  Rajesh Biswas
// CF    :  rajesh_1920
// Date  :  18.01.2026

#include <bits/stdc++.h>
using namespace std;
//----------------------------(definition section)-----------------------------------------
#define dbg(x) cout << #x << " = " << x << '\n';
#define int long int
#define fi first
#define sc second

#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()

const double eps = 1e-1;
const int inf = 9e16 + 7;
const int MOD = 1e8;
const int N = 1e5 + 10;
//------------------------------(solve)----------------------------------------------------
int ok(int n, int par, int mx, vector<vector<int>> &v, vector<pair<int, int>> &vp, vector<vector<int>> &dp)
{
    if (dp[n][mx] != -1)
        return dp[n][mx];
    int ans = 0;
    for (auto &it : v[n])
    {
        if (it == par)
            continue;
        if (mx)
            ans += max(ok(it, n, 1, v, vp, dp) + abs(vp[n].sc - vp[it].sc),
                       ok(it, n, 0, v, vp, dp) + abs(vp[n].sc - vp[it].fi));
        else
            ans += max(ok(it, n, 1, v, vp, dp) + abs(vp[n].fi - vp[it].sc),
                       ok(it, n, 0, v, vp, dp) + abs(vp[n].fi - vp[it].fi));
    }
    return dp[n][mx] = ans;
}
void solve(void)
{
    int n;
    cin >> n;
    vector<pair<int, int>> vp(n);
    for (auto &it : vp)
        cin >> it.fi >> it.sc;
    vector<vector<int>> v(n);
    for (int i = 1, x, y; i < n; i++)
    {
        cin >> x >> y;
        v[x - 1].push_back(y - 1), v[y - 1].push_back(x - 1);
    }
    vector<vector<int>> dp1(n + 5, vector<int>(3, -1)), dp2(n + 5, vector<int>(3, -1));
    int ans = ok(0, -1, 0, v, vp, dp1);
    ans = max(ans, ok(0, -1, 1, v, vp, dp2));
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