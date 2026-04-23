// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  10.03.2025

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
int dp[110][N];
int ok(int n, int val, vector<int> &v, vector<int> &w)
{
    if (val <= 0)
        return 0;
    if (n == 0)
        return inf;
    if (dp[n][val] != -1)
        return dp[n][val];
    int an = inf;
    an = min(an, ok(n - 1, val, v, w));
    an = min(an, ok(n - 1, val - v[n], v, w) + w[n]);
    return dp[n][val] = an;
}
void solve(void)
{
    memset(dp, -1, sizeof(dp));
    int n, wg, sum = 0;
    cin >> n >> wg;
    vector<int> v(n + 1), w(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i] >> v[i];
        sum += v[i];
    }
    int r = sum;
    while (true)
    {
        if (ok(n, r, v, w) <= wg)
        {
            cout << r;
            return;
        }
        r--;
    }
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