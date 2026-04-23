// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  31.10.2025

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
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n, -1));
    queue<pair<int, int>> q;
    q.push({0, 0});
    v[0][0] = 0;
    int x[] = {2, 2, -2, -2, 1, 1, -1, -1};
    int y[] = {1, -1, 1, -1, 2, -2, 2, -2};

    while (!q.empty())
    {
        auto [xx, yy] = q.front();
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            if (xx + x[i] >= n || xx + x[i] < 0 || yy + y[i] >= n || yy + y[i] < 0)
                continue;
            if (v[xx + x[i]][yy + y[i]] == -1)
            {
                v[xx + x[i]][yy + y[i]] = v[xx][yy] + 1;
                q.push({xx + x[i], yy + y[i]});
            }
        }
    }
    for (auto it : v)
    {
        for (auto ii : it)
            cout << ii << ' ';
        cout << '\n';
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