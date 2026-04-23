// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  11.04.2025

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
    int m;
    string s;
    cin >> m >> s;
    vector<int> v(m + 5, 0);
    for (int i = 1; i <= m; i++)
        v[i] = v[i - 1] + s[i - 1] - '0';
    map<int, int> mp;
    mp[0]++;
    int ans = 0;
    for (int i = 1; i <= m; i++)
    {
        v[i] %= 3;
        ans += mp[v[i]];
        mp[v[i]]++;
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