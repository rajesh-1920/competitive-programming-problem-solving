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
void ok(int n, int beg, int mid, int en)
{
    if (n == 1)
    {
        cout << beg << ' ' << en << '\n';
        return;
    }
    ok(n - 1, beg, en, mid);
    cout << beg << ' ' << en << '\n';
    ok(n - 1, mid, beg, en);
}
void solve(void)
{
    int n;
    cin >> n;
    int ans = 1;
    cout << ((ans <<= n) - 1) << '\n';
    ok(n, 1, 2, 3);
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