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
    map<int, int> mp;
    int ans = 0;
    int i = 0, j = 0;
    while (i < n)
    {
        mp[v[i]]++;
        if (mp.size() > k)
            break;
        i++;
    }
    ans = i * (i + 1) / 2;
    if (i < n)
        mp.erase(v[i]);
    while (i < n)
    {
        mp[v[i]]++;
        while (mp.size() > k)
        {
            mp[v[j]]--;
            if (mp[v[j]] == 0)
                mp.erase(v[j]);
            j++;
        }
        ans += (i - j + 1);
        i++;
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
    // cin >> test;
    for (T = 1; T <= test; T++)
    {
        // cout << "Case " << T << ": ";
        solve();
    }
    return 0;
}