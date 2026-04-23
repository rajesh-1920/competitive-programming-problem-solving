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
//------------------------------(solve)-----------------------------------------------------
void solve(void)
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> v(n + 1, vector<int>(n + 1, inf));
    for (int i = 0, x, y, z; i < m; i++)
    {
        cin >> x >> y >> z;
        v[x][y] = v[y][x] = min(v[x][y], z);
    }
    for (int i = 1; i <= n; i++)
        v[i][i] = 0;
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        cout << (v[x][y] == inf ? -1 : v[x][y]) << '\n';
    }
}
//-----------------------------------------------------------------------------------------
signed main()
{
    // cout << fixed << showpoint << setprecision(10);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1, T;
    // cin >> test;
    for (T = 1; T <= test; T++)
    {
        // cout << "Case " << T << ": ";
        solve();
    }
    return 0;
}