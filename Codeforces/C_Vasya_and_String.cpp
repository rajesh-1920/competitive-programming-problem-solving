// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  15.02.2026

#include <bits/stdc++.h>
using namespace std;
//----------------------------(definition section)-----------------------------------------
#define dbg(x) cout << #x << " = " << x << '\n'
#define fi first
#define sc second
#define int long long int

#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()

const double eps = 1e-1;
const int MOD = 1e9 + 7;
const int N = 1e7 + 1;
//-----------------------------------------------------------------------------------------
void solve(void)
{
    int n, k;
    string s;
    cin >> n >> k >> s;
    int ans = 0, l = 0, r = n;
    while (l <= r)
    {
        int m = (l + r) / 2;
        int ca = 0, cb = 0, fl = 0;
        for (int i = 0; i < m; i++)
            if (s[i] == 'a')
                ca++;
            else
                cb++;
        if (min(ca, cb) <= k)
            fl = 1;
        for (int i = m; i < n; i++)
        {
            if (fl)
                break;
            if (s[i - m] == 'a')
                ca--;
            else
                cb--;
            if (s[i] == 'a')
                ca++;
            else
                cb++;
            if (min(ca, cb) <= k)
                fl = 1;
        }
        if (fl)
            ans = max(ans, m), l = m + 1;
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