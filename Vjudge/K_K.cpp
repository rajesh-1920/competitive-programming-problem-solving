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
int ok(int n)
{
    if (n == 2)
        return 1;
    int ans = 0;
    for (int i = 1; i <= 2*n; i++)
    {
        for (int j = i; j <= 2*n; j++)
        {
            int t = i * j;
            if (t == i + j + (n - 2))
            {
                ans += (n - 1) * n;
            }
        }
    }
    return ans;
}
void solve(void)
{
    int n, p;
    cin >> n >> p;
    for (int i = 3; i <= n; i+=2)
    {
        // if (i == 2)
        //     cout << 1 % p << ' ';
        // else if (i == 3)
        //     cout << 6 % p << ' ';
        // else if (i & 1)
        //     cout << (i * (i - 1) * 2) % p << ' ';
        // else
        //     cout << (i * (i - 1)) % p << ' ';

        cout << i << ' ' << ok(i) << '\n';
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