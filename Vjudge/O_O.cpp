// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  28.08.2025

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
    int n, ans = 10;
    string s;
    cin >> n >> s;
    for (int c = 2; c < 8; c++)
    {
        for (int i = 0; i + c <= n; i++)
        {
            int ca = 0, cb = 0, cc = 0;
            for (int j = i; j < i + c; j++)
            {
                if (s[j] == 'a')
                    ca++;
                if (s[j] == 'b')
                    cb++;
                if (s[j] == 'c')
                    cc++;
            }
            if (ca > cb && ca > cc)
                ans = min(ans, c);
        }
    }
    if (ans == 10)
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