// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  27.07.2025

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
    int n, k;
    cin >> n >> k;
    vector<int> v(62, 0);
    for (int i = 0; i < n; i++)
    {
        int x, ii = 0;
        cin >> x;
        while (x)
        {
            if (x & 1)
                v[ii]++;
            ii++;
            x /= 2;
        }
    }
    int s = 1;
    for (int i = 0; i < 62; i++)
    {
        if (v[i] < n)
        {
            int t = n - v[i];
            int need = s * t;
            if (need <= k)
            {
                k -= need;
                v[i] = n;
            }
            else
            {
                v[i] += k / s;
                // dbg(k / s);
                break;
            }
        }
        s *= 2;
    }
    int ans = 0;
    for (int i = 0; i < 62; i++)
    {
        // cout << v[i] << ' ';
        ans += v[i];
    }
    cout << ans << '\n';
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