// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  11.09.2025

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
    int n, gc = 0;
    cin >> n;
    vector<int> v(n), lgcd(n, 0), rgcd(n, 0);
    for (auto &it : v)
    {
        cin >> it;
        gc = gcd(it, gc);
    }
    for (int i = 1; i < n; i++)
        lgcd[i] = gcd(v[i - 1], lgcd[i - 1]);
    for (int i = n - 2; i >= 0; i--)
        rgcd[i] = gcd(v[i + 1], rgcd[i + 1]);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int g = gcd(lgcd[i], rgcd[i]);
        if (gc != 1)
            g = gcd(g, 1);
        else if (i)
            g = gcd(g, v[i - 1]);
        else
            g = gcd(g, v[i + 1]);
        if (g != gc)
            ans++;
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