// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  13.02.2025

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
    int n;
    cin >> n;
    int ans = 1;
    if (n == 1)
        ans = 1;
    else if (n == 2)
        ans = 2;
    else
    {
        if (n & 1)
            ans = n * (n - 1) * (n - 2);
        else
        {
            ans = (n - 1) * (n - 2) * (n - 3);
            if (n % 3 != 0)
            {
                int t = (n) * (n - 1) * (n - 3);
                ans = max(ans, t);
            }
            else
            {
                int t = (n/2) * (n - 1) * (n - 2);
                ans = max(ans, t);
            }
        }
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