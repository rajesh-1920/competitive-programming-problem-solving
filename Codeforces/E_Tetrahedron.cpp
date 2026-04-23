// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  14.02.2026

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
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 2; i <= n; i++)
        if (i & 1)
            ans = ((ans - 1) * 3) % MOD;
        else
            ans = ((ans + 1) * 3) % MOD;
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