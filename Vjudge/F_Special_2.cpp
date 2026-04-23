// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  25.03.2025

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
    int n, m, q;
    cin >> n >> m >> q;
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        int gc = __gcd(x, y);
        int mx = 0;
        for (int i = 1; i * i <= gc + 5; i++)
        {
            if (gc % i == 0)
            {
                if (i <= m)
                    mx = max(mx, i);
                if (gc / i <= m)
                    mx = max(mx, gc / i);
            }
        }
        //dbg(mx);
        cout << (m - mx + 1) << '\n';
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