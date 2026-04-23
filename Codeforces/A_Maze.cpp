// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  27.07.2025

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
const int N = 1e3 + 10;
//------------------------------(solve)----------------------------------------------------

int vis[N][N], depth[N][N];

void dfs(int row, int col, int &n, int &m)
{
    vis[row][col] = 1;
    queue<pair<int, int>> q;
    q.push({row, col});
    while (!q.empty())
    {
        row = q.front().fi;
        col = q.front().sc;
        q.pop();
        if (row > 0 && vis[row - 1][col] == 0)
        {
            depth[row - 1][col] = depth[row][col] + 1;
            vis[row - 1][col] = 1;
            q.push({row - 1, col});
        }
        if (row + 1 < n && vis[row + 1][col] == 0)
        {
            depth[row + 1][col] = depth[row][col] + 1;
            vis[row + 1][col] = 1;
            q.push({row + 1, col});
        }
        if (col > 0 && vis[row][col - 1] == 0)
        {
            depth[row][col - 1] = depth[row][col] + 1;
            vis[row][col - 1] = 1;
            q.push({row, col - 1});
        }
        if (col + 1 < m && vis[row][col + 1] == 0)
        {
            depth[row][col + 1] = depth[row][col] + 1;
            vis[row][col + 1] = 1;
            q.push({row, col + 1});
        }
    }
}

void solve(void)
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> maze(n);
    int row, col;
    for (int i = 0; i < n; i++)
    {
        cin >> maze[i];
        for (int j = 0; j < m; j++)
        {
            if (maze[i][j] == '.')
                row = i, col = j, vis[i][j] = 0;
            else
                vis[i][j] = 1;
            depth[i][j] = 0;
        }
    }
    if (k)
    {
        dfs(row, col, n, m);
        priority_queue<pair<int, pair<int, int>>> pq;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (maze[i][j] == '.')
                    pq.push({depth[i][j], {i, j}});
            }
        }
        while (k--)
        {
            maze[pq.top().sc.fi][pq.top().sc.sc] = 'X';
            pq.pop();
        }
    }
    for (auto it : maze)
        cout << it << '\n';
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