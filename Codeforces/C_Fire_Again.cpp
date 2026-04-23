// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  13.11.2025

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
void solve(void)
{
    int n, m, k, mx = -1;
    cin >> n >> m >> k;
    vector<vector<int>> lev(n, vector<int>(m, -1));
    queue<pair<int, int>> q;
    for (int i = 0, x, y; i < k; i++)
    {
        cin >> x >> y;
        x--, y--;
        q.push({x, y});
        lev[x][y] = 0;
    }
    pair<int, int> ans;
    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
        if (lev[x][y] > mx)
            ans = {x + 1, y + 1};
        if (x + 1 < n && lev[x + 1][y] == -1)
            q.push({x + 1, y}), lev[x + 1][y] = lev[x][y] + 1;
        if (x - 1 >= 0 && lev[x - 1][y] == -1)
            q.push({x - 1, y}), lev[x - 1][y] = lev[x][y] + 1;
        if (y + 1 < m && lev[x][y + 1] == -1)
            q.push({x, y + 1}), lev[x][y + 1] = lev[x][y] + 1;
        if (y - 1 >= 0 && lev[x][y - 1] == -1)
            q.push({x, y - 1}), lev[x][y - 1] = lev[x][y] + 1;
    }
    cout << ans.fi << ' ' << ans.sc << '\n';
}
//-----------------------------------------------------------------------------------------
signed main()
{
    // cout << fixed << showpoint << setprecision(10);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int test = 1, T;
    // cin >> test;
    for (T = 1; T <= test; T++)
    {
        // cout << "Case " << T << ": ";
        solve();
    }
    return 0;
}