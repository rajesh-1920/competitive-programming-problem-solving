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
int f(int x, vector<int> &v)
{
    int s = 0;
    for (auto it : v)
        s += abs(it - x);
    return s;
}
void solve(void)
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &it : v)
        cin >> it;
    int ans = inf, l = 0, r = MOD;
    while (l <= r)
    {
        int m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
        int t1 = f(m1, v), t2 = f(m2, v);
        if (t1 > t2)
            ans = min(ans, t2), l = m1 + 1;
        else if (t1 < t2)
            ans = min(ans, t1), r = m2 - 1;
        else
            ans = min(ans, t1), r = m2 - 1, l = m1 + 1;
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