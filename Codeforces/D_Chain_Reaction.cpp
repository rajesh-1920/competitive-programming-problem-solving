// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  11.04.2025

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
void solve(void)
{
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (auto &it : v)
        cin >> it.fi >> it.sc;
    sort(all(v));
    vector<int> pos(n), dp(n + 5, 0);
    for (int i = 0; i < n; i++)
        pos[i] = v[i].fi;
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        int l = v[i].fi - v[i].sc;
        int ii = (lower_bound(all(pos), l) - pos.begin());
        if (ii)
            dp[i] = dp[ii - 1] + 1;
        else
            dp[i] = 1;
        mx = max(mx, dp[i]);
    }
    cout << (n - mx);
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