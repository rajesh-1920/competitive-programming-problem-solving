// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  22.07.2025

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
    int n, d;
    cin >> n >> d;
    vector<int> v(n);
    for (auto &it : v)
        cin >> it;

    int ans = 0;
    int i = 0, j = 0, prej = -1;

    while (i < n)
    {
        while (j < n)
        {
            if (v[j] - v[i] > d)
                break;
            j++;
        }
        int t = j - i;
        if (v[j - 1] - v[i] <= d && prej != j)
        {
            ans += (t) * (t - 1) * (t - 2) / 6;
            if (i < prej)
            {
                t = prej - i;
                ans -= (t) * (t - 1) * (t - 2) / 6;
            }
            prej = j;
        }
        i++;
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