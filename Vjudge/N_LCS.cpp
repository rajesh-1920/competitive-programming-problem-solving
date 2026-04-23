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
const int N = 3e3 + 10;
//-----------------------------------------------------------------------------------------
int dp[N][N];
int ok(int i, int j, string &s1, string &s2)
{
    if (i == s1.size() || j == s2.size())
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int ans = 0;
    if (s1[i] == s2[j])
        ans = max(ans, ok(i + 1, j + 1, s1, s2) + 1);
    else
    {
        ans = max(ans, ok(i, j + 1, s1, s2));
        ans = max(ans, ok(i + 1, j, s1, s2));
    }
    return dp[i][j] = ans;
}
string s = "";
void path(int i, int j, string &s1, string &s2)
{
    if (i == s1.size() || j == s2.size())
        return;
    if (s1[i] == s2[j])
    {
        s.push_back(s1[i]);
        path(i + 1, j + 1, s1, s2);
    }
    else
    {
        if (ok(i + 1, j, s1, s2) > ok(i, j + 1, s1, s2))
            path(i + 1, j, s1, s2);
        else
            path(i, j + 1, s1, s2);
    }
}
void solve(void)
{
    memset(dp, -1, sizeof(dp));
    string s1, s2;
    cin >> s1 >> s2;
    s1 = s1;
    s2 = s2;
    int x = ok(0, 0, s1, s2);
    path(0, 0, s1, s2);
    cout << s;
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