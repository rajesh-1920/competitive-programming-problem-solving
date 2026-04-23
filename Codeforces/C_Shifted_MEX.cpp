// Author:  Rajesh Biswas
// CF    :  rajesh_1920
// Date  :  18.01.2026

#include <bits/stdc++.h>
using namespace std;
//----------------------------(definition section)-----------------------------------------
#define dbg(x) cout << #x << " = " << x << '\n';
#define int long int
#define fi first
#define sc second

#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()

const double eps = 1e-1;
const int inf = 9e16 + 7;
const int MOD = 1e8;
const int N = 1e5 + 10;
//------------------------------(solve)----------------------------------------------------
void solve(void)
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &it : v)
        cin >> it;
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        map<int, int> mp;
        int x = -v[i];
        for (int j = 0; j < n; j++)
            mp[v[j] + x]++;
        for (int j = 0; j <= n + 10; j++)
            if (mp[j] == 0)
            {
                mx = max(mx, j);
                break;
            }
    }
    cout << mx << '\n';
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