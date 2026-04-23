// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  29.01.2025

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
    int n, m, ans = 0, t = 0;
    cin >> n >> m;
    while (n--)
    {
        int x;
        cin >> x;
        t += x;
        if (t > m)
        {
            ans++;
            t = x;
        }
        else if (t == m)
        {
            ans++;
            t = 0;
        }
    }
    if (t)
        ans++;
    cout << ans << ' ';
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