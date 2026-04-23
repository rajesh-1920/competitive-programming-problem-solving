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
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &it : v)
        cin >> it;
    map<int, vector<pair<int, int>>> mp;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (j == i)
                continue;
            mp[v[i] + v[j]].push_back({i + 1, j + 1});
        }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            int t = k - v[i] - v[j];
            if (mp.find(t) != mp.end())
            {
                for (auto it : mp[t])
                    if (it.fi != i + 1 && it.fi != j + 1 && it.sc != i + 1 && it.sc != j + 1)
                    {
                        cout << i + 1 << ' ' << j + 1 << ' ' << it.fi << ' ' << it.sc << '\n';
                        return;
                    }
            }
        }
    cout << "IMPOSSIBLE\n";
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