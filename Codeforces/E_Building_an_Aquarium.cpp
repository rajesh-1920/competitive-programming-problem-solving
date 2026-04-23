// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  11.07.2025

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
//------------------------------(solve)----------------------------------------------------
void solve(void)
{
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for (auto &it : v)
        cin >> it;
    int ans = 0, l = 0, r = inf;
    sort(all(v));
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        int s = 0;
        for (auto it : v)
        {
            if (it >= m || s > x)
                break;
            s += m - it;
        }
        if (s <= x)
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
    cin >> test;
    for (T = 1; T <= test; T++)
    {
        // cout << "Case " << T << ": ";
        solve();
    }
    return 0;
}