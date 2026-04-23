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
int ok(int x, vector<pair<int, int>> &v)
{
    int p = 0, l = 0, r = v.size() - 1;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (v[m].fi > x)
            r = m - 1;
        else if (v[m].fi < x)
            l = m + 1;
        else
            p = m, r = m - 1;
    }
    return p;
}
void solve(void)
{
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> v(n);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i - 1].fi;
        v[i - 1].sc = i;
    }
    sort(all(v));
    for (auto it : v)
    {
        if (it.fi >= x)
            break;
        int t = x - it.fi;
        int p = ok(t, v);
        if (v[p].fi == t && v[p].sc != it.sc)
        {
            cout << min(it.sc, v[p].sc) << ' ' << max(it.sc, v[p].sc) << '\n';
            return;
        }
        if (p + 1 < n && v[p + 1].fi == t && v[p + 1].sc != it.sc)
        {
            cout << min(it.sc, v[p + 1].sc) << ' ' << max(it.sc, v[p + 1].sc) << '\n';
            return;
        }
    }
    cout << "IMPOSSIBLE\n";
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