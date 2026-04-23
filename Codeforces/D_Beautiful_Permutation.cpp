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
void solve(void)
{
    int n;
    cin >> n;
    int r = n, l = 1, left = 0;
    while (r >= l)
    {
        int m = (l + r) / 2;
        int p, a;
        cout << 1 << ' ' << 1 << ' ' << m << '\n';
        cin >> p;
        cout << 2 << ' ' << 1 << ' ' << m << '\n';
        cin >> a;

        if (a == p)
        {
            left = m;
            l = m + 1;
        }
        else
            r = m - 1;
    }
    int p, a;
    cout << 1 << ' ' << left+1 << ' ' << n << '\n';
    cin >> p;
    cout << 2 << ' ' << left+1 << ' ' << n << '\n';
    cin >> a;
    int right = left + (a - p);
    left++;
    cout << "! " << left << ' ' << right << '\n';
}
//-----------------------------------------------------------------------------------------
signed main()
{
    int test = 1, T;
    cin >> test;
    for (T = 1; T <= test; T++)
    {
        // cout << "Case " << T << ": ";
        solve();
    }
    return 0;
}