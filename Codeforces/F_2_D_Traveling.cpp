// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  24.04.2025

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
    int n, k, a, b;
    cin >> n >> k >> a >> b;
    a--, b--;
    vector<pair<int, int>> v(n);
    for (auto &it : v)
        cin >> it.fi >> it.sc;
    int ans = abs(v[a].fi - v[b].fi) + abs(v[a].sc - v[b].sc);
    if (a < k && b < k)
        ans = 0;
    int t1 = inf, t2 = inf;
    for (int i = 0; i < k; i++)
        t1 = min(t1, 1LL * (abs(v[a].fi - v[i].fi) + abs(v[a].sc - v[i].sc)));
    for (int i = 0; i < k; i++)
        t2 = min(t2, 1LL * (abs(v[b].fi - v[i].fi) + abs(v[b].sc - v[i].sc)));
    ans = min(ans, (t1 + t2));
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