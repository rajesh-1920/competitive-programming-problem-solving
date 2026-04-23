// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  10.03.2025

#include <bits/stdc++.h>
using namespace std;
//----------------------------(definition section)-----------------------------------------
#define dbg(x) cout << #x << " = " << x << '\n'
#define int long int
#define fi first
#define sc second

#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()

const double eps = 1e-1;
const int inf = 9e16 + 7;
const int MOD = 1e9 + 7;
const int N = 1e3 + 10;
//-----------------------------------------------------------------------------------------
char grid[N][N];
int dp[N][N];
int ok(int h, int w)
{
    if (h == 1 && 1 == w)
        return 1;
    if (dp[h][w] != -1)
        return dp[h][w];
    int ans = 0;
    if (h > 1)
        if (grid[h - 1][w] == '.')
            ans += ok(h - 1, w);
    if (w > 1)
        if (grid[h][w - 1] == '.')
            ans += ok(h, w - 1);
    ans %= MOD;
    return dp[h][w] = ans;
}
void solve(void)
{
    int h, w;
    cin >> h >> w;
    for (int i = 1; i <= h; i++)
        for (int j = 1; j <= w; j++)
        {
            cin >> grid[i][j];
            dp[i][j] = -1;
        }
    cout << (ok(h, w) % MOD) << '\n';

    // for (int i = 1; i <= h; i++)
    // {
    //     for (int j = 1; j <= w; j++)
    //     {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
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