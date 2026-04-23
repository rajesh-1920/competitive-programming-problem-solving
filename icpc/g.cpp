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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m, 0));
    for (auto &it : v)
        for (auto &ii : it)
            cin >> ii;
    vector<int> row(n), col(m);
    for (int i = 0; i < n; i++)
    {
        int x = 0;
        for (int j = 0; j < m; j++)
            x ^= v[i][j];
        row[i] = x;
    }
    for (int i = 0; i < m; i++)
    {
        int x = 0;
        for (int j = 0; j < n; j++)
            x ^= v[j][i];
        col[i] = x;
    }
    int ans = 0;
    for (auto it : row)
        ans += it;
    for (auto it : col)
        ans += it;
    int mn = ans;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int x = ans - row[i] - col[j];
            int c = col[j] ^ v[i][j];
            int r = row[i] ^ v[i][j];
            r ^= c;
            mn = min(mn, x + r);
            c = col[j] ^ v[i][j];
            r = row[i] ^ v[i][j];
            c ^= r;
            mn = min(mn, x + c);
        }
    }
    cout << mn << '\n';
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