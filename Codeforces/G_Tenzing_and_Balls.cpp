// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  17.05.2025

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
const int N = 2e5 + 10;
//-----------------------------------------------------------------------------------------
int dp[N][2];
int ok(int n, int fl, vector<int> &v, vector<int> &next)
{
    if (n == v.size())
        return 0;
    // dbg(n);
    if (dp[n][fl] != -1)
        return dp[n][fl];
    int ans = ok(n + 1, 1, v, next);
    ans = max(ans, ok(n + 1, 0, v, next));
    if (next[n] != v.size())
    {
        if (fl)
            ans = max(ans, ok(next[n], 0, v, next) + (next[n] - n + 1));
        ans = max(ans, ok(next[n], fl, v, next) + (next[n] - n));
    }
    return dp[n][fl] = ans;
}
void solve(void)
{
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    vector<int> v(n), next(n, n), temp(n, n);
    for (auto &it : v)
        cin >> it;
    for (int i = n - 1; i >= 0; i--)
    {
        next[i] = temp[v[i] - 1];
        temp[v[i] - 1] = i;
    }
    cout << ok(0, 1, v, next) << '\n';
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