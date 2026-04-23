// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  26.05.2025

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
    int n, k;
    string s;
    cin >> n >> k >> s;
    int c0 = 0, c1 = 0;
    for (auto it : s)
        if (it == '1')
            c1++;
        else
            c0++;
    while (k--)
    {
        if (c0 >= c1)
            c0 -= 2;
        else
            c1 -= 2;
    }
    if (c0 == 0 && c1 == 0)
        cout << "YES\n";
    else if (c0 != c1)
        cout << "NO\n";
    else
        cout << "YES\n";
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