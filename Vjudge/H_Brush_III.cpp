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
const int inf = 9e16 + 7;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;
//-----------------------------------------------------------------------------------------
int dp[110][110];
int ok(int n, int k, int &w, int &sz, vector<int> &v)
{
    if (n >= sz || k == 0)
        return 0;
    if (dp[n][k] != -1)
        return dp[n][k];
    int ans = ok(n + 1, k, w, sz, v);

    int x = upper_bound(all(v), v[n] + w) - v.begin();
    ans = max(ans, ok(x, k - 1, w, sz, v) + x - n);
    return dp[n][k] = ans;
}
void solve(void)
{
    memset(dp, -1, sizeof(dp));
    int n, w, k;
    cin >> n >> w >> k;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v.push_back(y);
    }
    sort(all(v));
    cout << ok(0, k, w, n, v) << '\n';
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