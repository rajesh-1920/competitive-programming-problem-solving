// Author:  Rajesh Biswas
// CF    :  rajesh_1920
// Date  :  13.01.2026

#include <bits/stdc++.h>
using namespace std;
//----------------------------(definition section)-----------------------------------------
#define dbg(x) cout << #x << " = " << x << '\n';
#define fi first
#define sc second

#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()

const double eps = 1e-1;
const int inf = 1e9 + 7;
const int MOD = 1e9 + 7;
const int N = 1e6 + 10;
//------------------------------(solve)----------------------------------------------------
int dp[N][10], choise[N][10];
int ok(int n, int i, vector<int> &v)
{
    if (i <= 0 || n <= 0)
        return 0;
    if (dp[n][i] != -1)
        return dp[n][i];
    int ans = ok(n, i - 1, v);
    choise[n][i] = 0;
    if (n >= v[i])
    {
        int next = ok(n - v[i], i, v) + 1;
        if (next >= ans)
        {
            ans = next;
            choise[n][i] = 1;
        }
        next = ok(n - v[i], i - 1, v) + 1;
        if (next > ans)
        {
            ans = next;
            choise[n][i] = 2;
        }
    }
    return dp[n][i] = ans;
}
void path(int n, int i, vector<int> &v, vector<int> &ans)
{
    if (n <= 0 || i <= 0)
        return;
    if (choise[n][i] == 0)
        path(n, i - 1, v, ans);
    else if (choise[n][i] == 1)
    {
        ans.push_back(i);
        path(n - v[i], i, v, ans);
    }
    else
    {
        ans.push_back(i);
        path(n - v[i], i - 1, v, ans);
    }
}
void solve(void)
{
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 1, x; i <= 9; i++)
    {
        cin >> x;
        mp[x] = max(mp[x], i);
    }
    vector<int> v(10, inf);
    for (auto &it : mp)
        v[it.sc] = it.fi;
    int t = ok(n, 9, v);
    if (t == 0)
    {
        cout << -1 << '\n';
        return;
    }
    vector<int> ans;
    path(n, 9, v, ans);
    sort(rall(ans));
    for (auto &it : ans)
        cout << it;
    cout << '\n';
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