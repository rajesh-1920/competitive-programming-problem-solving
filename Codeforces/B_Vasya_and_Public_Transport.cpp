// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  28.01.2025

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
    int n, m, c1, c2, c3, c4;
    cin >> c1 >> c2 >> c3 >> c4 >> n >> m;
    int a[n + 5], b[m + 5];
    int bus = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        bus += min(c2, c1 * a[i]);
    }
    bus = min(c3, bus);
    int troly = 0;
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
        troly += min(c2, b[i] * c1);
    }
    troly = min(c3, troly);
    cout << min(c4, (bus + troly));
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