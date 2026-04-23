// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  02.02.2025

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
const int N = 200 + 10;
//-----------------------------------------------------------------------------------------

void solve(void)
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m), cnt(15, 0), arr(15, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i - 1];
        int x = a[i - 1], j = 0;
        while (x)
        {
            if (x & 1)
                cnt[j]++;
            j++;
            x /= 2;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i - 1];
        int x = b[i - 1], j = 0;
        while (x)
        {
            if (x & 1)
                arr[j]++;
            j++;
            x /= 2;
        }
    }
    int t = n;
    for (int i = 14; i >= 0; i--)
    {
        if (cnt[i] > 0 && t >= cnt[i])
        {
            // cout << cnt[i] << ' ';
            if (arr[i] != m)
            {
                while (cnt[i])
                {
                    if (t == 0)
                        break;
                    t--;
                    cnt[i]--;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 14; i++)
    {
        if (cnt[i])
        {
            ans |= 1 << i;
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
    // cin >> test;
    for (T = 1; T <= test; T++)
    {
        // cout << "Case " << T << ": ";
        solve();
    }
    return 0;
}