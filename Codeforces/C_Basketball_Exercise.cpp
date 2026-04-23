// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  16.06.2025

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
int dp[N][3];
int ok(int i, int p, vector<int> &v, vector<int> &b)
{
    if (i == v.size())
        return 0;
    if (dp[i][p] != -1)
        return dp[i][p];
    int ans = ok(i + 1, 0, v, b);
    if (p == 0)
    {
        ans = max(ans, ok(i + 1, 1, v, b) + v[i]);
        ans = max(ans, ok(i + 1, 2, v, b) + b[i]);
    }
    if (p == 1)
        ans = max(ans, ok(i + 1, 2, v, b) + b[i]);
    if (p == 2)
        ans = max(ans, ok(i + 1, 1, v, b) + v[i]);
    return dp[i][p] = ans;
}
void solve(void)
{
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    vector<int> v(n), b(n);
    for (auto &it : v)
        cin >> it;
    for (auto &it : b)
        cin >> it;
    cout << ok(0, 0, v, b) << '\n';
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