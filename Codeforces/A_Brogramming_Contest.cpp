// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  16.02.2025

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
    string s;
    int n;
    cin >> n >> s;
    int ans = 0;
    int fl = 0;
    char t = 'a';
    for (auto it : s)
    {
        if (it == '1' && fl == 0)
        {
            fl = 1;
            ans++;
            t = it;
            continue;
        }
        if (fl)
        {
            if (t != it)
                ans++;
        }
        t = it;
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