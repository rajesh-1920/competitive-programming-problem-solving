// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  13.11.2025

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
bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    if (a.sc == b.sc)
        return a.fi < b.fi;
    return a.sc < b.sc;
}
void solve(void)
{
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (auto &it : v)
        cin >> it.fi >> it.sc;
    sort(all(v), cmp);
    int ans = 1, last = v.front().sc;
    for (int i = 1; i < n; i++)
    {
        if (last <= v[i].fi)
            ans++, last = v[i].sc;
    }
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