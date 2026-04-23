// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  28.02.2025

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
    vector<int> v(n);
    for (auto &it : v)
        cin >> it;
    int ans = 0, cnt = 0, f0 = -1, l1 = -1;
    for (int i = 0; i < n; i++)
    {
        if (v[i])
        {
            cnt++;
            l1 = i;
        }
        else
        {
            ans += cnt;
            if (f0 == -1)
                f0 = i;
        }
    }
    if (l1 != -1)
    {
        v[l1] = 0;
        int t = 0, cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (v[i])
                cnt++;
            else
                t += cnt;
        }
        v[l1] = 1;
        ans = max(ans, t);
    }
    if (f0 != -1)
    {
        v[f0] = 1;
        int t = 0, cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (v[i])
                cnt++;
            else
                t += cnt;
        }
        ans = max(ans, t);
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