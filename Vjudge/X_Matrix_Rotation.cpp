// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  17.03.2025

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
    int a[2][2];
    cin >> a[0][0] >> a[0][1] >> a[1][0] >> a[1][1];
    int t = 10;
    while (t--)
    {
        if (a[0][0] < a[1][0] && a[0][0] < a[0][1] && a[1][0] < a[1][1] && a[0][1] < a[1][1])
        {
            cout << "YES\n";
            return;
        }
        int temp = a[0][0];
        a[0][0] = a[1][0];
        a[1][0] = a[1][1];
        a[1][1] = a[0][1];
        a[0][1] = temp;
    }
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