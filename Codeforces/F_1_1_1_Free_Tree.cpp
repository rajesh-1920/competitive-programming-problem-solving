// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  11.07.2025

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
const int N = 2e5 + 10;
//------------------------------(solve)----------------------------------------------------
void solve(void)
{
    int n, q;
    cin >> n >> q;
    vector<pair<int, int>> g[n + 5];
    vector<int> color(n + 5);
    for (int i = 1; i <= n; i++)
        cin >> color[i];
    for (int i = 1; i < n; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        g[x].push_back({y, z});
        g[y].push_back({x, z});
    }
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        for (auto it : g[i])
        {
            if (i < it.fi && color[i] != color[it.fi])
                sum += it.sc;
        }
    }
    vector<int> temp(n + 5, -1);
    while (q--)
    {
        int v, x;
        cin >> v >> x;
        if (color[v] != x)
        {
            for (auto it : g[v])
            {
                if (color[v] != color[it.fi])
                
                    sum -= it.sc;
                if (x != color[it.fi])
                    sum += it.sc;
            }
            temp[x] = sum;
        }
        color[v] = x;
        cout << sum << '\n';
    }
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