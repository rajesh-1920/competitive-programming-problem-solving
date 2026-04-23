// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  08.03.2025

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
vector<int> dp(N, -1);
int ans(int n, vector<int> &v)
{
    if (n == 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    int an = inf;
    if (n >= 1)
        an = min(an, ans(n - 1, v) + max(v[n - 1] - v[n], v[n] - v[n - 1]));
    if (n >= 2)
        an = min(an, ans(n - 2, v) + max(v[n - 2] - v[n], v[n] - v[n - 2]));
    return dp[n] = an;
}
void solve(void)
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &it : v)
        cin >> it;
    cout << ans(n - 1, v);
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