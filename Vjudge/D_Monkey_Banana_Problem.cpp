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
const int N = 1e3 + 10;
//-----------------------------------------------------------------------------------------
vector<int> v[N];
int dp[N][N];
int ok(int i, int j, int &n)
{
    if (i == 0 || j < 0 || j >= v[i].size())
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int ans = 0;
    if (i > n)
    {
        ans = max(ans, ok(i - 1, j, n) + v[i][j]);
        ans = max(ans, ok(i - 1, j + 1, n) + v[i][j]);
    }
    else
    {
        ans = max(ans, ok(i - 1, j, n) + v[i][j]);
        ans = max(ans, ok(i - 1, j - 1, n) + v[i][j]);
    }
    return dp[i][j] = ans;
}
void solve(void)
{
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        v[i].push_back(0);
        v[i].clear();
        for (int j = 1; j <= i; j++)
        {
            int x;
            cin >> x;
            v[i].push_back(x);
        }
    }
    int t = n + 1;
    for (int i = n - 1; i > 0; i--)
    {
        v[t].push_back(0);
        v[t].clear();
        for (int j = 1; j <= i; j++)
        {
            int x;
            cin >> x;
            v[t].push_back(x);
        }
        t++;
    }
    // for (int i = 1; i < t; i++)
    // {
    //     for (auto it : v[i])
    //         cout << it << ' ';
    //     cout << '\n';
    // }
    cout << ok(t - 1, 0, n) << '\n';
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