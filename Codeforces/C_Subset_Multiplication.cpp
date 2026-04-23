// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  06.07.2025

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
    int lc = 1;
    for (int i = 1; i < n; i++)
        lc = max(lc, (v[i - 1]) / (__gcd(v[i], v[i - 1])));
    for (int i = lc;; i += lc)
    {
        int temp = v.back();
        int fl = 1;
        for (int j = n - 2; j >= 0; j--)
        {
            int yy = v[j];
            if (temp % yy && (yy % i == 0))
                yy /= i;
            if (yy)
            {
                if (temp % yy)
                    fl = 0;
            }
            else
                fl = 0;
            temp = yy;
        }
        if (fl)
        {
            cout << i << '\n';
            return;
        }
    }
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