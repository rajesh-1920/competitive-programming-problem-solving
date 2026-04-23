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

const int N = 2e5 + 10;
//------------------------------(solve)----------------------------------------------------
void solve(void)
{
    int n, m, q;
    cin >> n >> m >> q;

    vector<int> a(n), b(m);
    for (auto &it : a)
        cin >> it;
    for (auto &it : b)
        cin >> it;

    sort(rall(a));
    sort(rall(b));

    vector<int> suma(n + 1, 0), sumb(m + 1, 0);
    for (int i = 1; i <= n; i++)
        suma[i] = suma[i - 1] + a[i - 1];
    for (int i = 1; i <= m; i++)
        sumb[i] = sumb[i - 1] + b[i - 1];

    while (q--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        int left = max(0LL, z - y), right = min(x, z);
        if (left > right)
        {
            cout << 0 << '\n';
            continue;
        }
        int ans = 0;
        while (right - left > 3)
        {
            int m1 = left + (right - left) / 3;
            int m2 = right - (right - left) / 3;
            int f1 = suma[m1] + sumb[z - m1];
            int f2 = suma[m2] + sumb[z - m2];
            if (f1 < f2)
                left = m1;
            else
                right = m2;
        }
        for (int t = left; t <= right; t++)
            ans = max(ans, suma[t] + sumb[z - t]);

        cout << ans << '\n';
    }
}
//-----------------------------------------------------------------------------------------
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin >> test;
    for (int T = 1; T <= test; T++)
        solve();
    return 0;
}
