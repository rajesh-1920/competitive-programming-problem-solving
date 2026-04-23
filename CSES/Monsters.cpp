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
    vector<string> v(n);
    for (auto &it : v)
        cin >> it;
    vector<vector<int>> mn_mon(n, vector<int>(m, inf)), mn_ch(n, vector<int>(m, 0));
    queue<pair<int, int>> pq;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (v[i][j] == 'M')
                pq.push({i, j}), mn_mon[i][j] = 0;
    vector<int> mvx = {0, 0, 1, -1}, mvy = {1, -1, 0, 0};
    while (!pq.empty())
    {
        int vx = pq.front().fi, vy = pq.front().sc;
        pq.pop();
        for (int i = 0; i < 4; i++)
        {
            int x = vx + mvx[i], y = vy + mvy[i];
            if (x >= 0 && x < n && y >= 0 && y < m && v[x][y] != '#')
                if (mn_mon[x][y] > mn_mon[vx][vy] + 1)
                    pq.push({x, y}), mn_mon[x][y] = mn_mon[vx][vy] + 1;
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (v[i][j] == 'A')
            {
                pq.push({i, j}), v[i][j] = '#';
                break;
            }
    vector<vector<pair<int, int>>> par(n, vector<pair<int, int>>(m, {-1, -1}));
    while (!pq.empty())
    {
        int vx = pq.front().fi, vy = pq.front().sc;
        if (vx == 0 || vx == n - 1 || vy == 0 || vy == m - 1)
        {
            cout << "YES\n";
            string s;
            while (true)
            {
                int t1 = par[vx][vy].fi, t2 = par[vx][vy].sc;
                if (t1 == -1)
                    break;
                if (t1 < vx)
                    s.push_back('D');
                if (t1 > vx)
                    s.push_back('U');
                if (t2 > vy)
                    s.push_back('L');
                if (t2 < vy)
                    s.push_back('R');
                vx = t1, vy = t2;
            }
            reverse(all(s));
            cout << s.size() << '\n';
            cout << s << '\n';
            return;
        }
        pq.pop();
        for (int i = 0; i < 4; i++)
        {
            int x = vx + mvx[i], y = vy + mvy[i];
            if (x >= 0 && x < n && y >= 0 && y < m && v[x][y] != '#')
                if (mn_mon[x][y] > mn_ch[vx][vy] + 1)
                    pq.push({x, y}), mn_ch[x][y] = mn_ch[vx][vy] + 1, v[x][y] = '#', par[x][y] = {vx, vy};
        }
    }
    cout << "NO\n";
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