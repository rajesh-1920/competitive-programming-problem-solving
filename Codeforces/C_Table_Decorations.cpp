// Author:  Rajesh Biswas
// CF    :  rajesh_1920
// Date  :  01.06.2026

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
    vector<int> v(3);
    cin >> v[0] >> v[1] >> v[2];
    sort(all(v));
    int ans = 0, l = 0, r = inf;
    while (l <= r)
    {
        int m = (l + r) / 2, fl = 0;
        if (v.front() >= m)
            fl = 1;
        else
        {
            int lagbe = v.front() * 2, ace = v[1] + v.back();
            if (ace >= lagbe)
            {
                int rakbo = ace - lagbe;
                int banate_parbo = rakbo / 3;
                if (v.front() + min({v[1], v.back(), banate_parbo}) >= m)
                    fl = 1;
            }
        }
        if (fl)
            ans = m, l = m + 1;
        else
            r = m - 1;
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