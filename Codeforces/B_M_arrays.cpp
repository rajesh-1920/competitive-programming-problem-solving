// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  25.03.2025

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
    map<int, int> mp;
    vector<int> v(n);
    for (auto &it : v)
    {
        cin >> it;
        it %= m;
        mp[it]++;
    }
    sort(all(v));
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (mp[v[i]] > 0 && v[i] > 0)
        {
            int x = m - v[i];
            if (mp[x] == mp[v[i]])
                mp[x] = mp[v[i]] = -1;
            else if (mp[x] > mp[v[i]])
            {
                mp[x] -= (mp[v[i]] + 1);
                mp[v[i]] = 0;
            }
            else
            {
                mp[v[i]] -= (mp[x] + 1);
                mp[x] = 0;
            }
            ans++;
        }
    }
    for (auto it : mp)
        if (it.sc > 0)
            ans++;
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