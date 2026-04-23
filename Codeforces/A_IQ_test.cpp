// Author:  Rajesh Biswas
// CF    :  rajesh_1920
// Date  :  04.01.2026

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
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;
//------------------------------(solve)----------------------------------------------------
void solve(void)
{
    int n;
    cin >> n;
    int c0 = 0, p0, c1 = 0, p1;
    for (int i = 1, x; i <= n; i++)
    {
        cin >> x;
        if (x & 1)
        {
            if (c1 > 1)
            {
                cout << i << '\n';
                return;
            }
            c0++;
            p0 = i;
        }
        else
        {
            if (c0 > 1)
            {
                cout << i << '\n';
                return;
            }
            c1++;
            p1 = i;
        }
    }
    if (c0 < c1)
        p1 = p0;
    cout << p1 << '\n';
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