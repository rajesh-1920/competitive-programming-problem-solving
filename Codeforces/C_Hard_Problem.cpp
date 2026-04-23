// Author:  Rajesh Biswas
// CF    :  rajesh_1920
// Date  :  11.01.2026

#include <bits/stdc++.h>
using namespace std;
//----------------------------(definition section)-----------------------------------------
#define dbg(x) cout << #x << " = " << x << '\n';
#define int long long int
#define fi first
#define sc second

#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()

const double eps = 1e-1;
const int inf = 9e16 + 7;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;
//------------------------------(solve)----------------------------------------------------
int dp[N][2];
int ok(int i, int fl, vector<int> &cost, vector<string> &s)
{
    if (i == cost.size())
        return 0;
    if (dp[i][fl] >= 0)
        return dp[i][fl];
    int ans = inf;
    string t = s[i];
    reverse(all(t));
    if (fl == 0)
    {
        int c = 1;
        if (s[i - 1] <= s[i])
            ans = min(ans, ok(i + 1, 0, cost, s)), c = 0;
        if (s[i - 1] <= t)
            ans = min(ans, ok(i + 1, 1, cost, s) + cost[i]), c = 0;
        if (c)
            return inf;
    }
    else
    {
        int c = 1;
        string temp = s[i - 1];
        reverse(all(temp));
        if (temp <= s[i])
            ans = min(ans, ok(i + 1, 0, cost, s)), c = 0;
        if (temp <= t)
            ans = min(ans, ok(i + 1, 1, cost, s) + cost[i]), c = 0;
        if (c)
            return inf;
    }
    return dp[i][fl] = ans;
}
void solve(void)
{
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    vector<int> cost(n);
    vector<string> s(n);
    for (auto &it : cost)
        cin >> it;
    for (auto &it : s)
        cin >> it;
    int ans = ok(1, 0, cost, s);
    ans = min(ans, ok(1, 1, cost, s) + cost.front());
    if (ans >= inf)
        ans = -1;
    cout << ans << '\n';
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