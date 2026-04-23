// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  17.10.2025

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
bool ok(int n, int m, vector<pair<int, int>> &range, vector<int> &query)
{
    vector<int> v(n, 0);
    for (int i = 0; i < m; i++)
        v[query[i] - 1] = 1;
    for (int i = 1; i < n; i++)
        v[i] += v[i - 1];
    for (auto it : range)
    {
        int s = 0;
        if (it.fi == 1)
            s += v[it.sc - 1];
        else
            s += v[it.sc - 1] - v[it.fi - 2];
        int len = (it.sc - it.fi + 1);
        len = (len + 2) / 2;
        if (s >= len)
            return true;
    }
    return false;
}
void solve(void)
{
    int n, m, q;
    cin >> n >> m;
    vector<pair<int, int>> range(m);
    for (int i = 0; i < m; i++)
        cin >> range[i].fi >> range[i].sc;
    cin >> q;
    vector<int> query(q);
    for (int i = 0; i < q; i++)
        cin >> query[i];

    int ans = -1, l = 1, r = q;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (ok(n, mid, range, query))
            ans = mid, r = mid - 1;
        else
            l = mid + 1;
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