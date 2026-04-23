// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  17.02.2025

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
    int n;
    cin >> n;
    vector<int> v(n), sum(n + 1, 0), s(n + 1, 0);
    int i = 1;
    for (auto &it : v)
    {
        cin >> it;
        if (it > 0)
            s[i] = s[i - 1] + it;
        else
            s[i] = s[i - 1];
        i++;
    }
    int ans = -inf;
    for (int i = n - 1; i >= 0; i--)
    {
        if (v[i] < 0)
            sum[i] = sum[i + 1] - v[i];
        else
            sum[i] = sum[i + 1];
    }
    for (int i = 0; i <= n; i++)
        ans = max(ans, s[i] + sum[i]);
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