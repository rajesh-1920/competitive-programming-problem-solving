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
void solve(void)
{
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> v(n);
    for (auto &it : v)
        cin >> it;
    int ans = -inf;
    int i = 0, j = 0, s = 0;
    while (j < n)
    {
        if (i == n)
        {
            if (i - j + 1 >= a & i - j + 1 <= b)
                ans = max(ans, s);
            s -= v[j];
            j++;
        }
        else
        {
            if (i - j + 1 >= a & i - j + 1 <= b)
                ans = max(ans, s);
            s += v[i];
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