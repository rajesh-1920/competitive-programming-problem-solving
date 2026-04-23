// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  15.08.2025

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
const int N = 5e2 + 10;
//------------------------------(solve)----------------------------------------------------
// int dp[N];

// int ok(int i, vector<int> path[], vector<int> &vis)
// {
//     if (i >= vis.size())
//         return i;
//     if (dp[i] != -1)
//         return dp[i];
//     int ans = i;
//     for (auto it : path[i])
//     {
//         if (!vis[it])
//         {
//             vis[it] = 1;
//             ans = max(ans, ok(i + 1, path, vis));
//             vis[it] = 0;
//         }
//     }
//     return dp[i] = ans;
// }

void solve(void)
{
    // memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n));
    vector<vector<int>> sum(n, vector<int>(n, 0));
    for (auto &it : v)
        for (auto &ii : it)
            cin >> ii;
    vector<int> path[n + 5], vis(n + 5, 0);
    int t = 1;
    for (int i = 0; i < n; i++)
        path[0].push_back(i);
    for (int j = n - 2; j >= 0; j--)
    {
        for (int i = 0; i < n; i++)
        {
            sum[i][j] = sum[i][j + 1] + v[i][j + 1];
            if (sum[i][j] == t)
                path[t].push_back(i);
        }
        t++;
    }

    for (auto &it : sum)
    {
        // for (auto ii : it)
        //     cout << ii << ' ';
        // cout << '\n';
        sort(all(it));
    }
    sort(all(sum));
    int ans = 0;
    // for (auto it : sum)
    // {
    //     for (auto ii : it)
    //         cout << ii << ' ';
    //     cout << '\n';
    // }
    // cout << '\n';

    for (int i = n - 1; i >= 0; i--)
    {
        int x = i, j = 0, t = 0;
        while (x >= 0 && j < n)
        {
            if (sum[x][j] != t)
                break;
            x--,j++;
            t++;
        }
        //dbg(t);
        ans = max(ans, t);
    }
    cout << ans << '\n';

    // cout << ok(0, path, vis) << '\n';
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