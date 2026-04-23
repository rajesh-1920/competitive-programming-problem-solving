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
const int MOD = 100000007;
const int N = 1000 + 10;
//-----------------------------------------------------------------------------------------
inline int normal(int a, int m)
{
    a = a - (a / m) * m;
    if (a < 0)
        a += m;
    return a;
}
inline int modadd(int a, int b, int m)
{
    a = normal(a, m), b = normal(b, m);
    return normal(a + b, m);
}
//-----------------------------------------------------------------------------------------
int dp[55][N];
int ok(int n, int k, vector<int> &v, vector<int> &c)
{
    if (k == 0)
        return 1;
    if (n == 0)
        return 0;
    if (dp[n][k] != -1)
        return dp[n][k];
    int ways = 0;
    for (int i = 0; i <= c[n]; i++)
        if (k >= i * v[n])
            ways = modadd(ways, ok(n - 1, k - i * v[n], v, c), MOD);
        else
            break;
    return dp[n][k] = normal(ways, MOD);
}
void solve(void)
{
    memset(dp, -1, sizeof(dp));
    int n, k;
    cin >> n >> k;
    vector<int> v(n + 1), c(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    cout << ok(n, k, v, c) << '\n';
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