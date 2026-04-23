// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  08.02.2025

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
    int n, x;
    cin >> n >> x;
    int ans = 0;
    for (int a = 1; a <= n; a++)
        for (int b = 1; a * b < n; b++)
        {
            int c = (n - (a * b)) / (a + b);
            if (c > 0)
            {
                if (a + b + c <= x)
                    ans += c;
                else
                {
                    int t = x - a - b;
                    if (t > 0)
                        ans += t;
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
    cin >> test;
    for (T = 1; T <= test; T++)
    {
        // cout << "Case " << T << ": ";
        solve();
    }
    return 0;
}