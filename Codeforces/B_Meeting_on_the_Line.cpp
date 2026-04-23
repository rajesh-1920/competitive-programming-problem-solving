// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  19.10.2025

#include <bits/stdc++.h>
using namespace std;
//----------------------------(definition section)-----------------------------------------
#define dbg(x) cout << #x << " = " << x << '\n';
#define int long long int
#define fi first
#define sc second

#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()

const double eps = 1e-7;
const int inf = 9e16 + 7;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;
//------------------------------(solve)----------------------------------------------------
void solve(void)
{
    int n, cnt = 200;
    cin >> n;
    vector<double> v(n), t(n);
    for (auto &it : v)
        cin >> it;
    for (auto &it : t)
        cin >> it;
    double l = 0, r = MOD;
    while (cnt-- && l < r)
    {
        double m1 = l + (r - l) / 2;
        double t1 = 0, t2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (v[i] >= m1)
                t1 = max(t1, t[i] + v[i] - m1);
            else
                t2 = max(t2, t[i] + m1 - v[i]);
        }
        if (t1 < t2)
            r = m1;
        else
            l = m1;
    }
    cout << (l + r) / 2.0 << '\n';
}
//-----------------------------------------------------------------------------------------
signed main()
{
    cout << fixed << showpoint << setprecision(7);
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