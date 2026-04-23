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
    int n, k;
    cin >> n >> k;

    int mxx = 31;
    vector<int> pwr3(mxx), d(mxx, 0);
    pwr3[0] = 1;
    for (int i = 1; i < mxx; i++)
        pwr3[i] = pwr3[i - 1] * 3;

    int tmp = n, idx = 0, m = 0;
    while (tmp > 0)
    {
        d[idx++] = tmp % 3;
        tmp /= 3;
    }
    for (int i = 0; i < mxx; i++)
    {
        m += d[i];
        if (m > k)
        {
            cout << -1 << "\n";
            return;
        }
    }
    int tar = min(k, n);
    if ((tar - m) & 1)
        tar--;
    if (tar < m)
    {
        cout << -1 << "\n";
        return;
    }
    int div = (tar - m) / 2;
    for (int i = mxx - 1; i > 0; i--)
        if (d[i])
        {
            int nibo = min(d[i], div);
            d[i] -= nibo;
            d[i - 1] += nibo * 3;
            div -= nibo;
            if (div <= 0)
                break;
        }

    if (div)
    {
        cout << -1 << "\n";
        return;
    }

    int ans = 0, cnt[mxx];
    cnt[0] = 3;
    for (int i = 1; i + 1 < mxx; i++)
        cnt[i] = pwr3[i + 1] + i * pwr3[i - 1];

    for (int i = 0; i < mxx; i++)
        ans += d[i] * cnt[i];

    cout << ans << "\n";
}
//-----------------------------------------------------------------------------------------
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1, T;
    cin >> test;
    for (T = 1; T <= test; T++)
    {
        solve();
    }
    return 0;
}
