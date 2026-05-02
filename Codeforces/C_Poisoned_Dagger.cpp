// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  01.05.2026

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
const int inf = 1e18 + 7;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;
//-----------------------------------------------------------------------------------------
void solve(void)
{
    int n, h;
    cin >> n >> h;
    vector<int> v(n);
    for (auto &it : v)
        cin >> it;
    sort(all(v));
    int ans = inf, l = 0, r = inf;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        int s = m;
        for (int i = 0; i + 1 < n; i++)
        {
            if (s >= h)
                break;
            if (v[i] + m <= v[i + 1])
                s += m;
            else
                s += v[i + 1] - v[i];
        }
        if (s >= h)
            ans = m, r = m - 1;
        else
            l = m + 1;
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
    cin >> test;
    for (T = 1; T <= test; T++)
    {
        // cout << "Case " << T << ": ";
        solve();
    }
    return 0;
}