// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  10.03.2025

#include <bits/stdc++.h>
using namespace std;
//----------------------------(definition section)-----------------------------------------
#define dbg(x) cout << #x << " = " << x << '\n'
// #define int long long int
#define fi first
#define sc second

#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()

const double eps = 1e-1;
const int inf = 9e5 + 7;
const int MOD = 1e9 + 7;
const int N = 2e2 + 10;
//-----------------------------------------------------------------------------------------
int dp[N][N];
int ok(int i, int j, string &s)
{
    if (j <= i || j < 0 || i >= s.size())
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int ans = inf;
    if (s[i] == s[j])
        ans = min(ans, ok(i + 1, j - 1, s));
    else
    {
        ans = min(ans, ok(i + 1, j, s) + 1);
        ans = min(ans, ok(i, j - 1, s) + 1);
    }
    return dp[i][j] = ans;
}
void solve(void)
{
    memset(dp, -1, sizeof(dp));
    string s;
    cin >> s;
    cout << ok(0, s.size() - 1, s) << '\n';
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
        cout << "Case " << T << ": ";
        solve();
    }
    return 0;
}