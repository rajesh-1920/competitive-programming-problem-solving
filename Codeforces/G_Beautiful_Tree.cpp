// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  17.10.2025

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
bool is_perfect_square(int x)
{
    int s = sqrt(x);
    return s * s == x;
}

void solve(void)
{
    int n;
    cin >> n;
    if (n < 2)
    {
        cout << -1 << "\n";
        return;
    }
    int S = n * (n + 1) / 2 - 1;
    if (n == 3)
    {
        cout << 1 << ' ' << 3 << '\n';
        cout << 2 << ' ' << 3 << '\n';
        return;
    }
    if (is_perfect_square(S))
    {
        for (int i = 2; i <= n; ++i)
            cout << 1 << " " << i << "\n";
    }
    else
    {
        cout << -1 << "\n";
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