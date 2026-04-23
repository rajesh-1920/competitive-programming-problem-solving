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
    vector<string> s(n);
    for (auto &it : s)
        cin >> it;
    int xs, ys, xe, ye;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (s[i][j] == 'A')
                xs = i, ys = j;
            else if (s[i][j] == 'B')
                xe = i, ye = j;
    vector<vector<pair<int, int>>> par(n, vector<pair<int, int>>(m, {-1, -1}));
    queue<pair<int, int>> q;
    vector<int> x = {0, 0, 1, -1}, y = {1, -1, 0, 0};
    q.push({xs, ys});
    s[xs][ys] = '#';
    while (!q.empty())
    {
        int i = q.front().fi, j = q.front().sc;
        q.pop();
        for (int t = 0; t < 4; t++)
        {
            int xx = i + x[t], yy = j + y[t];
            if (xx >= 0 && xx < n && yy >= 0 && yy < m && s[xx][yy] != '#')
            {
                q.push({xx, yy});
                s[xx][yy] = '#';
                par[xx][yy] = {i, j};
            }
        }
    }
    if (s[xe][ye] == 'B')
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    string ans;
    while (true)
    {
        int t1 = par[xe][ye].fi, t2 = par[xe][ye].sc;
        if (t1 == -1)
            break;
        if (t1 < xe)
            ans.push_back('D');
        if (t1 > xe)
            ans.push_back('U');
        if (t2 < ye)
            ans.push_back('R');
        if (t2 > ye)
            ans.push_back('L');
        xe = t1, ye = t2;
    }
    reverse(all(ans));
    cout << ans.size() << '\n';
    cout << ans << '\n';
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