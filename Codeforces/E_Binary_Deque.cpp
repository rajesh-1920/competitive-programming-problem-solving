// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  21.08.2025

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
//------------------------------(solve)----------------------------------------------------
void solve(void)
{
    int n, s = 0, sum;
    cin >> n >> sum;
    vector<int> v(n);
    for (auto &it : v)
        cin >> it, s += it;
    // vector<vector<int>> v(110, vector<int>(110, 0));
    if (s < sum)
    {
        cout << -1 << '\n';
        return;
    }
    s = 0;
    int ans = n, l = 0, r = 0;
    while (r < n)
    {
        s += v[r];
        r++;
        if (s == sum)
        {
            while (r < n && v[r] == 0)
                r++;
            break;
        }
    }
    ans = min(ans, n - r);
    while (r < n)
    {
        r++;
        s++;
        while (r < n && v[r] == 0)
            r++;
        while (s != sum)
        {
            s -= v[l];
            l++;
        }
        ans = min(ans, (n - r + l));
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