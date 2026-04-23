// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  18.02.2025

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
    vector<vector<int>> v(n, vector<int>(m));
    map<int, int> mp, t;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
            mp[v[i][j]]++;
            if (i > 0)
            {
                if (v[i][j] == v[i - 1][j])
                    t[v[i][j]]++;
            }
            if (j > 0)
            {
                if (v[i][j] == v[i][j - 1])
                    t[v[i][j]]++;
            }
        }
    }
    int tar = v[0][0], maxmp = 0;
    for (auto it : t)
    {
        if (it.second > maxmp)
        {
            maxmp = it.second;
            tar = it.first;
        }
    }
    t[tar]++;
    t.erase(tar);
    int cnt = 0;
    for (auto it : mp)
    {
        if (it.first != tar)
        {
            //dbg(tar);
            cnt++;
        }
    }
    int x = t.size();
    cout << cnt + x << '\n';
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