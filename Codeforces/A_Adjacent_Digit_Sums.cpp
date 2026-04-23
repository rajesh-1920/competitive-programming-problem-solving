// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  11.02.2025

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
    int x, y;
    cin >> x >> y;
    int diff = x - y + 1;
    if (diff >= 9 && diff % 9 == 0)
        cout << "Yes\n";
    else if (y == x + 1)
        cout << "Yes\n";
    else if (y == 1 && x % 9 == 0)
        cout << "Yes\n";
    else
        cout << "No\n";
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