// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  11.04.2025

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
    int a, b, n, m, t;
    cin >> a >> b >> m >> n >> t;
    int ax = a, ay = b;
    t = 90 - t;
    int bad = cos(acos(-1) * t / 180) * b;
    // dbg(bad);
    ax = a + bad;
    t = (ax + m - 1) / m;
    ax = t * m;
    // dbg(ax);
    ay = ax * n / m;
    if (ay < b)
    {
        ay = b;
        t = (ay + n - 1) / n;
        ay = t * n;
        ax = ay * m / n;
    }
    cout << ax << ' ' << ay << '\n';
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