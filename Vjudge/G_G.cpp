// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  31.10.2025

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
    int x = 1, y, k;
    cin >> y >> k;
    int loop = 1e5, cnt = 0;
    while (loop--)
    {
        if (cnt == k)
        {
            cout << x << '\n';
            return;
        }
        int g = gcd(x, y);
        if (g > 1)
            break;
        x += g;
        cnt++;
    }
    if (gcd(x, y) == 1)
    {
        if (k <= y)
            cout << k;
        else
        {
            k -= y;
            cout << y * k + y << '\n';
        }
        return;
    }
    k -= cnt;
    int g = gcd(x, y);
    int t = y / g - 1;
    if (k < t)
    {
        cout << x + (g * k) << '\n';
        return;
    }
    else
    {
        k -= t;
        cout << y * k + y << '\n';
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