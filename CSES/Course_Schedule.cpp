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
    vector<vector<int>> v(n + 1);
    vector<int> in(n + 1, 0), ans;
    for (int i = 0, x, y; i < m; i++)
    {
        cin >> x >> y;
        v[x].push_back(y);
        in[y]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (in[i] == 0)
            q.push(i);
    while (!q.empty())
    {
        int nd = q.front();
        q.pop();
        ans.push_back(nd);
        for (auto it : v[nd])
        {
            in[it]--;
            if (in[it] == 0)
                q.push(it);
        }
    }
    if (ans.size() != n)
        cout << "IMPOSSIBLE\n";
    else
        for (auto it : ans)
            cout << it << ' ';
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