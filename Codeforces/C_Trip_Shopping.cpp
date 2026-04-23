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
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> v(n);
    for (auto &it : v)
        cin >> it.fi;
    for (auto &it : v)
        cin >> it.sc;
    sort(all(v));
    int ans = 0;
    for (auto it : v)
        ans += max(it.fi - it.sc, it.sc - it.fi);
    int mn = INT_MAX;
    for (int i = 1; i < n; i++)
    {
        vector<int> temp = {v[i].fi, v[i].sc, v[i - 1].fi, v[i - 1].sc};
        int x = max(v[i].fi - v[i].sc, v[i].sc - v[i].fi);
        x += max(v[i - 1].fi - v[i - 1].sc, v[i - 1].sc - v[i - 1].fi);
        sort(all(temp));
        int mx = 0;
        do
        {
            int t1 = max(temp[0] - temp[1], temp[1] - temp[0]);
            int t2 = max(temp[2] - temp[3], temp[2] - temp[3]);
            mx = max(mx, t1 + t2 - x);
        } while (next_permutation(all(temp)));
        mn = min(mx, mn);
    }
    cout << ans + mn << '\n';
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