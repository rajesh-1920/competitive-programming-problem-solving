// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  31.07.2025

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
    int n, x;
    string s;
    cin >> n >> x >> s;
    int l = -1, r = n;
    for (int i = x; i < n; i++)
    {
        if (s[i] == '#')
        {
            r = i;
            break;
        }
    }
    for (int i = x - 2; i >= 0; i--)
    {
        if (s[i] == '#')
        {
            l = i;
            break;
        }
    }
    if (l == -1 && r == n)
        cout << 1 << '\n';
    else if (l == -1)
        cout << min(x, (n - r + 1)) << '\n';
    else if (r == n)
        cout << min(l + 2, (n - x + 1)) << '\n';
    else
    {
        int t1 = min(x, n - r + 1);
        int t2 = min(l + 2, n - x + 1);
        cout << max(t1, t2) << '\n';
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