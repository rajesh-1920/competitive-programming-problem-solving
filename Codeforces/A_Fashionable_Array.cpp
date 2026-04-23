// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  24.05.2025

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
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &it : v)
        cin >> it;
    sort(all(v));
    int fod = inf, lod = -inf, fev = inf, lev = -inf;
    for (int i = 0; i < n; i++)
        if (v[i] & 1)
        {
            fod = i;
            break;
        }
    for (int i = 0; i < n; i++)
        if (v[i] % 2 == 0)
        {
            fev = i;
            break;
        }
    for (int i = n - 1; i >= 0; i--)
        if (v[i] & 1)
        {
            lod = i;
            break;
        }
    for (int i = n - 1; i >= 0; i--)
        if (v[i] % 2 == 0)
        {
            lev = i;
            break;
        }
    int ans = min(fev + (n - lev - 1), (fod + (n - lod - 1)));
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