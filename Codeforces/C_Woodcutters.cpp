// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  28.05.2025

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
int dp[N][2];
int ok(int n, int fl, vector<pair<int, int>> &v)
{
    // dbg(fl);
    if (n == v.size() - 1)
        return 0;
    if (dp[n][fl] != -1)
        return dp[n][fl];

    int ans = ok(n + 1, 0, v);
    if (fl == 0)
    {
        if (v[n + 1].fi > v[n].fi + v[n].sc)
            ans = max(ans, ok(n + 1, 1, v) + 1);
        if (v[n - 1].fi < v[n].fi - v[n].sc)
            ans = max(ans, ok(n + 1, 0, v) + 1);
    }
    if (fl == 1)
    {
        if (v[n + 1].fi > v[n].fi + v[n].sc)
            ans = max(ans, ok(n + 1, 1, v) + 1);
        if (v[n - 1].fi + v[n - 1].sc < v[n].fi - v[n].sc)
            ans = max(ans, ok(n + 1, 0, v) + 1);
    }
    return dp[n][fl] = ans;
}
void solve(void)
{
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    vector<pair<int, int>> v(n + 2);
    for (int i = 1; i <= n; i++)
        cin >> v[i].fi >> v[i].sc;

    v[0].fi = -inf;
    v[n + 1].fi = inf;
    v[0].sc = v[n + 1].sc = 0;

    sort(all(v));
    cout << ok(1, 0, v) << '\n';
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