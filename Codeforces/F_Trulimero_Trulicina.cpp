// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  13.04.2025

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
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> ans(n, vector<int>(m));
    // map<int, int> mp, mt;
    if (k == 2)
    {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                ans[i][j] = (i + j) % 2 + 1;
    }
    else
    {
        int curr = 1;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                ans[i][j] = curr;
                // mp[curr]++;
                curr = curr % k + 1;
            }
            if (m % k == 0)
            {
                curr = (curr + 1) % k;
                if (curr == 0)
                    curr = k;
            }
        }
    }
    // for (auto it : mp)
    //     mt[it.sc]++;
    // cout << mt.size() << '\n';

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
            cout << ans[i][j] << " ";
        cout << "\n";
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