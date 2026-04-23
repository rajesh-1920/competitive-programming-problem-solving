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
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> v(n);
    for (auto &it : v)
        cin >> it.fi;
    for (auto &it : v)
        cin >> it.sc;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        for (int j = v[i].fi - v[i].sc; j <= v[i].fi + v[i].sc; j++)
        {
            int t = (int)sqrt((v[i].sc * v[i].sc) - ((j - v[i].fi) * (j - v[i].fi)));
            t = 2 * t + 1;
            mp[j] = max(mp[j], t);
        }
    }
    int ans = 0;
    for (auto it : mp)
        ans += it.sc;
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