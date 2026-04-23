// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  26.05.2025

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
const int inf = 9e17 + 7;
const int MOD = 1e9 + 7;
const int N = 2e5 + 10;
//-----------------------------------------------------------------------------------------
vector<int> g[N];
int parent[N];

void bfs()
{
    queue<int> q;
    parent[1] = 0;
    q.push(1);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : g[u])
        {
            if (v == parent[u])
                continue;
            parent[v] = u;
            q.push(v);
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    int a[n + 5], dp[n + 5][2];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        g[i].clear();
        dp[i][0] = dp[i][1] = 0;
        parent[i] = 0;
    }
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    bfs();
    dp[1][0] = a[1];
    dp[1][1] = -a[1];
    queue<int> q;
    q.push(1);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : g[u])
        {
            if (v == parent[u])
                continue;
            dp[v][0] = max(a[v], a[v] + dp[u][1]);
            dp[v][1] = max(-a[v], -a[v] + dp[u][0]);
            q.push(v);
        }
    }
    for (int i = 1; i <= n; i++)
        cout << dp[i][0] << " ";
    cout << "\n";
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