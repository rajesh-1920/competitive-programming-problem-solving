// Author: Rajesh Biswas
// CF : rajesh-1920
// Date : 27.10.2025
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
const int MOD = 32768;
const int N = 1e5 + 10;
//------------------------------(solve)----------------------------------------------------
void solve(void)
{
    int n;
    cin >> n;
    while (n--)
    {
        int x, ans = inf;
        cin >> x;
        for (int i = 0; i <= 30; i++)
        {
            int t = x + i, cnt = 0;
            while (cnt < 30)
            {
                if (t % MOD == 0)
                {
                    ans = min(ans, i + cnt);
                    break;
                }
                cnt++;
                t <<= 1;
            }
        }
        cout << ans << ' ';
    }
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