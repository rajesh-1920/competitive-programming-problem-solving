// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  18.05.2025

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
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> v(n);
    for (auto &it : v)
        cin >> it;
    sort(all(v));
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int t1 = upper_bound(v.begin() + i + 1, v.end(), (r - v[i])) - v.begin();
        int t2 = lower_bound(v.begin() + i + 1, v.end(), (l - v[i])) - v.begin();
        ans += (max(0LL, t1 - t2));
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