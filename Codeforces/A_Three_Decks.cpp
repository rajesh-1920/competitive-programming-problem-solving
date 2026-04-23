// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  28.04.2025

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
    int a, b, c;
    cin >> a >> b >> c;
    int t = a + b + c;
    if (t % 3)
    {
        cout << "NO\n";
        return;
    }
    t /= 3;
    if (t < a || t < b)
    {
        cout << "NO\n";
        return;
    }
    c = c - (t - a);
    a = t;
    c = c - (t - b);
    b = t;
    if (c == a && a == b)
        cout << "YES\n";
    else
        cout << "NO\n";
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