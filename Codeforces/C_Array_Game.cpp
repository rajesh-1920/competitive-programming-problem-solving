// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  11.09.2025

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
    if (k >= 3)
    {
        cout << 0 << '\n';
        return;
    }
    set<int> t;
    int ans = 1e18 + 10;
    for (int i = 0; i < n; i++)
    {
        ans = min(ans, v[i]);
        for (int j = i + 1; j < n; j++)
            t.insert(abs(v[i] - v[j])), ans = min(ans, abs(v[i] - v[j]));
    }
    if (k == 2)
    {
        for (int i = 0; i < n; i++)
        {
            auto it = t.upper_bound(v[i]);
            if (it != t.end())
                ans = min(ans, abs(v[i] - (*it)));
            if (it != t.begin())
            {
                it--;
                ans = min(ans, abs(v[i] - (*it)));
            }
        }
    }
    cout << ans << '\n';
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