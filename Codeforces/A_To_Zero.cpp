// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  17.03.2025

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
    int n, k;
    cin >> n >> k;
    int ans = 0;
    if (n % 2 == 0)
    {
        if (k % 2 == 0)
            ans = ((n + k - 1) / k);
        else
        {
            k--;
            if (n > 0)
                ans += ((n + k - 1) / k);
        }
    }
    else
    {
        if (k % 2 == 1)
        {
            ans = 1;
            n -= k;
            k--;
            if (n > 0)
                ans += ((n + k - 1) / k);
        }
        else
        {
            ans = 1;
            n -= k;
            k--;
            if (n > 0)
                ans += ((n + k - 1) / k);
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
    cin >> test;
    for (T = 1; T <= test; T++)
    {
        // cout << "Case " << T << ": ";
        solve();
    }
    return 0;
}