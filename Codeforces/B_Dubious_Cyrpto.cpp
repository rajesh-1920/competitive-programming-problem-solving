// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  19.02.2026

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
const int N = 5e5 + 100;
//-----------------------------------------------------------------------------------------
void solve()
{
    int l, r, m;
    cin >> l >> r >> m;
    if (m < l)
    {
        cout << l << ' ' << l << ' ' << l + l - m << '\n';
        return;
    }
    else
        for (int i = r; i >= l; i--)
        {
            int md = m - (m / i) * i;
            if (md <= r - l)
            {
                cout << i << ' ' << r << ' ' << (r - md) << '\n';
                return;
            }
            md = i - md;
            if (md <= r - l)
            {
                cout << i << ' ' << r - md << ' ' << r << '\n';
                return;
            }
        }
    cout << r << ' ' << r << ' ' << r << '\n';
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