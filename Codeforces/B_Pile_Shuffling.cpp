// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  19.07.2025

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
    int n;
    cin >> n;
    vector<int> z(n), on(n), nz(n), non(n);
    int ans = 0, hate = 0, hon = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> z[i] >> on[i] >> nz[i] >> non[i];
        if (on[i] > non[i])
        {
            if (nz[i] < z[i])
            {
                hate += z[i] - nz[i];
                z[i] = nz[i];
            }
            ans += z[i];
            hon += on[i] - non[i];
            on[i] = non[i];
        }
        // dbg(ans);
    }
    ans += hon + hate;
    for (int i = 0; i < n; i++)
    {
        if (z[i] < nz[i])
        {
            if (hate >= (nz[i] - z[i]))
                hate -= (nz[i] - z[i]);
            else
            {
                int t = nz[i] - z[i];
                t -= hate;
                hate = 0;
                ans += t;
            }
        }
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