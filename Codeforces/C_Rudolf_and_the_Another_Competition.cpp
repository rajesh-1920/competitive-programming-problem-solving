// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  28.04.2025

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
bool cmp(pair<int, pair<int, int>> &a, pair<int, pair<int, int>> &b)
{
    if (a.sc.fi == b.sc.fi)
        if (a.sc.sc == b.sc.sc)
            return a.fi < b.fi;
        else
            return a.sc.sc < b.sc.sc;
    return a.sc.fi > b.sc.fi;
}
void solve(void)
{
    int n, m, h;
    cin >> n >> m >> h;
    vector<pair<int, pair<int, int>>> ans(n);
    for (int i = 0; i < n; i++)
    {
        multiset<int> v;
        for (int i = 0, it; i < m; i++)
            cin >> it, v.insert(it);
        int cnt = 0, pl = 0, f = 0;
        for (auto it : v)
        {
            if (pl + it > h)
                break;
            cnt++, pl += it, f += pl;
        }
        ans[i] = {i, {cnt, f}};
    }
    sort(all(ans), cmp);
    for (int i = 0; i < n; i++)
    {
        if (ans[i].fi == 0)
        {
            cout << i + 1 << '\n';
            return;
        }
    }
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
        // cout << "Case " << T << ": ";
        solve();
    }
    return 0;
}