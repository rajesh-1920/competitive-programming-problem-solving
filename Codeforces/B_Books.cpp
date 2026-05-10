// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  10.05.2026

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
    int n, t;
    cin >> n >> t;
    vector<int> v(n);
    for (auto &it : v)
        cin >> it;
    int ans = 0, l = 0, r = n;
    while (l <= r)
    {
        int m = l + (r - l) / 2, x = 0;
        for (int i = 0; i < m; i++)
            x += v[i];
        int fl = (x <= t);
        for (int i = m; i < n; i++)
        {
            if (fl)
                break;
            x -= v[i - m];
            x += v[i];
            fl = (x <= t);
        }
        if (fl)
            ans = m, l = m + 1;
        else
            r = m - 1;
    }
    cout << ans;
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