// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  15.02.2026

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
    if (n & 1)
        cout << 2 << '\n';
    else if ((n & (n - 1)) == 0)
        cout << -1 << '\n';
    else
    {
        for (int i = 3; i <= 10000000000 && i * (i + 1) <= 2 * n; i++)
        {
            int t = n - (i * (i + 1)) / 2;
            if (t - (t / i) * i == 0)
            {
                cout << i << '\n';
                return;
            }
        }
        cout << -1 << '\n';
    }
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