// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  19.10.2025

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
const int MOD = 1e9 + 7;
const int N = 1e3 + 10;
//------------------------------(solve)----------------------------------------------------
vector<int> need(N, inf);
void ok()
{
    need[1] = 0;
    for (int i = 1; i < N; i++)
    {
        for (int j = i; j; j--)
        {
            if (i + (i / j) >= N)
                break;
            need[i + (i / j)] = min(need[i + (i / j)], need[i] + 1);
        }
    }
}
int dp[N][12010];
int okk(int n, int k, const vector<int> &b, const vector<int> &c)
{
    if (n == b.size())
        return 0;
    if (dp[n][k] > -1)
        return dp[n][k];
    int ans = okk(n + 1, k, b, c);
    if (k - need[b[n]] >= 0)
        ans = max(ans, okk(n + 1, k - need[b[n]], b, c) + c[n]);
    return dp[n][k] = ans;
}
void solve(void)
{
    memset(dp, -1, sizeof(dp));
    int n, k;
    cin >> n >> k;
    vector<int> b(n), c(n);
    for (auto &it : b)
        cin >> it;
    int ans = 0;
    for (auto &it : c)
        cin >> it, ans += it;
    if (k < 12010)
        ans = okk(0, k, b, c);
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
    ok();
    for (T = 1; T <= test; T++)
    {
        // cout << "Case " << T << ": ";
        solve();
    }
    return 0;
}