// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  24.04.2025

#include <bits/stdc++.h>
using namespace std;
//----------------------------(definition section)-----------------------------------------
#define dbg(x) cout << #x << " = " << x << '\n'
#define fi first
#define sc second

#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()

const double eps = 1e-1;
const int inf = 9e16 + 7;
const int MOD = 1e9 + 7;
const int N = 2e9 + 10;
//-----------------------------------------------------------------------------------------
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto &it : a)
        cin >> it;
    for (auto &it : b)
        cin >> it;

    int cnt = 0;
    for (int it : a)
    {
        if (cnt < m && it >= b[cnt])
            cnt++;
        if (cnt == m)
        {
            cout << 0 << '\n';
            return;
        }
    }

    vector<int> pre(m + 1, n + 1), next(m, -1);
    pre[0] = 0;
    int j = 0;
    for (int i = 0; i < n; ++i)
    {
        if (j < m && a[i] >= b[j])
        {
            j++;
            pre[j] = i + 1;
        }
    }
    j = m - 1;
    for (int i = n - 1; i >= 0; --i)
    {
        if (j >= 0 && a[i] >= b[j])
        {
            next[j] = i;
            j--;
        }
    }

    for (auto it : next)
        cout << it << ' ';
    cout << '\n';

    int ans = N;
    for (int i = 0; i < m; ++i)
    {
        if (pre[i] > n)
            continue;
        if (i + 1 <= m - 1)
            if (next[i + 1] == -1 || pre[i] > next[i + 1])
                continue;
        ans = min(ans, b[i]);
    }
    if (ans >= 2e9)
        ans = -1;
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