// Author:  Rajesh Biswas
// CF    :  rajesh_1920
// Date  :  11.05.2026

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
int ok(int n, vector<int> &mp, vector<int> &dp)
{
    if (n >= N)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    int ans = ok(n + 1, mp, dp);
    ans = max(ans, ok(n + 2, mp, dp) + n * mp[n]);
    return dp[n] = ans;
}
void solve(void)
{
    int n;
    cin >> n;
    vector<int> dp(N, -1), mp(N, 0);
    for (int i = 0, x; i < n; i++)
    {
        cin >> x;
        mp[x]++;
    }
    cout << ok(0, mp, dp) << '\n';
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