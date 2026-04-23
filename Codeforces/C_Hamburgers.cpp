// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  29.05.2025

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
const int inf = 9e14 + 7;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;
//-----------------------------------------------------------------------------------------
void solve(void)
{
    string s;
    int nb, ns, nc, pb, ps, pc, r;
    cin >> s >> nb >> ns >> nc >> pb >> ps >> pc >> r;
    int cb = 0, cs = 0, cc = 0;
    for (auto it : s)
        if (it == 'B')
            cb++;
        else if (it == 'C')
            cc++;
        else
            cs++;
    int l = 0, rr = inf, ans = 0;
    while (l <= rr)
    {
        int m = (l + rr) / 2;
        int tb = cb * m - nb, ts = cs * m - ns, tc = cc * m - nc;
        tb = max(0LL, tb), tc = max(0LL, tc), ts = max(0LL, ts);
        int need = tb * pb + ts * ps + tc * pc;
        if (need <= r)
        {
            ans = max(ans, m);
            l = m + 1;
        }
        else
            rr = m - 1;
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