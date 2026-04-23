// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  22.07.2025

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
int gc(vector<int> &v)
{
    int g = 0;
    for (auto it : v)
        g = gcd(g, it);
    return g;
}
void solve(void)
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &it : v)
        cin >> it;
    int ans = 3;
    if (gc(v) == 1)
        ans = 0;

    int t = v.back();
    v[n - 1] = gcd(v[n - 1], n);
    if (gc(v) == 1)
        ans = min(ans, 1LL);
    v[n - 1] = t;
    if (n > 1)
    {
        v[n - 2] = gcd(v[n - 2], n - 1);
        if (gc(v) == 1)
            ans = min(ans, 2LL);
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