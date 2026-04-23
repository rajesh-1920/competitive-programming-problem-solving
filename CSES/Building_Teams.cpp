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
bool dfs(int n, vector<vector<int>> &g, vector<int> &col)
{
    bool ans = false;
    for (auto it : g[n])
    {
        if (col[it] == -1)
        {
            col[it] = col[n] == 1 ? 2 : 1;
            ans |= dfs(it, g, col);
            if (ans)
                return ans;
        }
        else if (col[it] == col[n])
            return true;
    }
    return ans;
}
void solve(void)
{
    int n, m;
    cin >> n >> m;
    vector<int> col(n + 1, -1);
    vector<vector<int>> g(n + 1);
    for (int i = 0, x, y; i < m; i++)
    {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = 1; i <= n; i++)
    {
        if (col[i] == -1)
        {
            col[i] = 1;
            if (dfs(i, g, col))
            {
                cout << "IMPOSSIBLE\n";
                return;
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << col[i] << ' ';
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