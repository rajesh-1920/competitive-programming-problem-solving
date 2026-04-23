// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  11.09.2025

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
bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.fi == b.fi)
        return a.sc < b.sc;
    return a.fi > b.fi;
}
bool cmp1(pair<int, int> a, pair<int, int> b)
{
    if (a.sc == b.sc)
        return a.fi > b.fi;
    return a.sc < b.sc;
}
void solve(void)
{
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (auto &it : v)
        cin >> it.fi >> it.sc;
    int ans = 0;
    sort(all(v), cmp);
    sort(v.begin() + (n / 2), v.end(), cmp1);
    for (int i = 0; i < n; i++)
    {
        ans += v[i].fi * i + v[i].sc * (n - i - 1);
        // dbg(v[i].fi);
    }
    int a1 = ans;
    sort(all(v), cmp1);
    sort(v.begin() + (n / 2), v.end(), cmp);
    ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += v[i].fi * i + v[i].sc * (n - i - 1);
        // dbg(v[i].fi);
    }
    cout << min(a1, ans) << '\n';
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