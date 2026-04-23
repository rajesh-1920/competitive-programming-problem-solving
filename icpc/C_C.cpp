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
void solve(void)
{
    int x, y;
    cin >> x >> y;
    vector<pair<int, int>> v;
    for (int i = 1; i * i <= y; i++)
    {
        if (y % i == 0)
            v.push_back({i, y / i});
    }
    for (auto it : v)
    {
        int t1 = min(it.fi, it.sc) - 1;
        if (t1 + t1 >= x && x >= t1)
        {
            cout << min(it.fi, it.sc) << ' ' << max(it.fi, it.sc) << '\n';
            cout << min(t1, x - t1) << ' ' << max(t1, x - t1) << '\n';
            return;
        }
        t1 = max(it.fi, it.sc) + 1;
        if (x >= t1 + t1)
        {
            cout << min(it.fi, it.sc) << ' ' << max(it.fi, it.sc) << '\n';
            cout << min(t1, x - t1) << ' ' << max(t1, x - t1) << '\n';
            return;
        }
    }
    cout << -1 << '\n';
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