// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  12.04.2025

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
    int n, m;
    cin >> n >> m;
    // vector<int> v(n); for (auto &it : v) cin >> it;
    // vector<vector<int>> v(110, vector<int>(110, 0));
    int ans = 0;
    if (m > 0)
    {
        if (m <= 2 * n)
        {
            ans = (m + 1) / 2;
            m = 0;
        }
        else
        {
            ans = n;
            m -= 2 * n;
        }
    }
    if (m > 0)
    {
        if (m <= (n - 2) * 2)
        {
            ans += (m + 1) / 2;
            m = 0;
        }
        else
        {
            ans += n - 2;
            m -= (n - 2) * 2;
        }
    }
    ans += m;
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