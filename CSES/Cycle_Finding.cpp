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
    vector<pair<pair<int, int>, int>> v(m);
    for (auto &it : v)
        cin >> it.fi.fi >> it.fi.sc >> it.sc;
    vector<int> dis(n + 1, inf), par(n + 1, -1);
    int x = -1;
    for (int i = 0; i < n; i++)
    {
        x = -1;
        for (auto it : v)
        {
            if (dis[it.fi.sc] > dis[it.fi.fi] + it.sc)
            {
                dis[it.fi.sc] = dis[it.fi.fi] + it.sc;
                par[it.fi.sc] = it.fi.fi;
                x = it.fi.sc;
            }
        }
    }
    if (x == -1)
        cout << "NO\n";
    else
    {
        for (int i = 0; i < n; ++i)
            x = par[x];
        cout << "YES\n";
        vector<int> ans;
        for (int t = x;; t = par[t])
        {
            ans.push_back(t);
            if (t == x && ans.size() > 1)
                break;
        }
        reverse(all(ans));
        for (auto it : ans)
            cout << it << ' ';
    }
}
//------------------------------------------------------------------------------------------
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