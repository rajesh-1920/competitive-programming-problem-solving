// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  18.02.2026

#include <bits/stdc++.h>
using namespace std;
//----------------------------(definition section)-----------------------------------------
#define dbg(x) cout << #x << " = " << x << '\n'
#define fi first
#define sc second
#define int long long int

#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()

const double eps = 1e-1;
const int MOD = 1e9 + 7;
const int N = 1e7 + 1;
//-----------------------------------------------------------------------------------------
void solve(void)
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n), sum(n, 0), mxsum(n, 0);
    for (auto &it : v)
        cin >> it;
    for (int t, i = 0; i < n; i++)
    {
        cin >> t;
        if (i)
            sum[i] = sum[i - 1], mxsum[i] = mxsum[i - 1];
        mxsum[i] += v[i];
        if (t)
            sum[i] += v[i];
    }
    int mx = 0;
    for (int i = 0; i + k - 1 < n; i++)
    {
        int s = sum[n - 1] - sum[i + k - 1] + mxsum[i + k - 1];
        if (i)
            s += sum[i - 1], s -= mxsum[i - 1];
        mx = max(mx, s);
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
    // cin >> test;
    for (T = 1; T <= test; T++)
    {
        // cout << "Case " << T << ": ";
        solve();
    }
    return 0;
}