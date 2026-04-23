// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  22.07.2025

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
//------------------------------(solve)----------------------------------------------------
void solve(void)
{
    int l, r;
    cin >> l >> r;
    int ans = r / 2 - (l - 1) / 2;
    ans += r / 3 - (l - 1) / 3;
    ans += r / 5 - (l - 1) / 5;
    ans += r / 7 - (l - 1) / 7;

    ans -= r / 6 - (l - 1) / 6;
    ans -= r / 10 - (l - 1) / 10;
    ans -= r / 14 - (l - 1) / 14;
    ans -= r / 15 - (l - 1) / 15;
    ans -= r / 21 - (l - 1) / 21;
    ans -= r / 35 - (l - 1) / 35;

    ans += r / 30 - (l - 1) / 30;
    ans += r / 42 - (l - 1) / 42;
    ans += r / 70 - (l - 1) / 70;
    ans += r / 105 - (l - 1) / 105;

    ans -= r / 210 - (l - 1) / 210;

    cout << r - l + 1 - ans << '\n';
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