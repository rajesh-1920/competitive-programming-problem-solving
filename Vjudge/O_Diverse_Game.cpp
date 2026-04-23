// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  22.03.2025

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
const int N = 1e5 + 10;
//-----------------------------------------------------------------------------------------
void solve(void)
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m)), w(n, vector<int>(m));
    map<int, int> mp;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
            mp[v[i][j]]++;
        }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            auto it = mp.upper_bound(v[i][j]);
            if (it == mp.end())
            {
                int t = (*mp.begin()).fi;
                if (t == v[i][j])
                {
                    cout << -1 << '\n';
                    return;
                }
                w[i][j] = t;
            }
            else
                w[i][j] = (*it).fi;
            mp[w[i][j]]--;
            if (mp[w[i][j]] == 0)
                mp.erase(mp[w[i][j]]);
        }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << w[i][j] << ' ';
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
    cin >> test;
    for (T = 1; T <= test; T++)
    {
        // cout << "Case " << T << ": ";
        solve();
    }
    return 0;
}