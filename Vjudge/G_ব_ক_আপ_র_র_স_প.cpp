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
    int a, b, c;
    cin >> a >> b >> c;
    int ans = min({a / 3, b / 2, c / 2});
    a -= 3 * ans;
    b -= 2 * ans;
    c -= 2 * ans;
    ans *= 7;
    int mx = 0;
    // dbg(ans);
    vector<int> v = {0, 1, 2, 3, 4, 5, 6, 0, 1, 2, 3, 4, 5, 6, 0, 1, 2, 3};
    /*
    0-sat, 1-sun, 2-mon, 3-tues 4-wed, 5-thurs, 6-fri
    */
    // dbg(a);
    // dbg(b);
    // dbg(c);
    // dbg(ans);
    for (int i = 0; i + 7 < v.size(); i++)
    {
        int t = 0;
        int x = a, y = b, z = c;
        for (int j = i; j <= i + 7; j++)
        {
            if (v[j] == 2 || v[j] == 5 || v[j] == 1)
            {
                if (a == 0)
                    break;
                a--, t++;
            }
            else if (v[j] == 3 || v[j] == 0)
            {
                if (b == 0)
                    break;
                b--, t++;
            }
            else
            {
                if (c == 0)
                    break;
                c--, t++;
            }
        }
        a = x, b = y, c = z;
        mx = max(t, mx);
    }
    cout << ans + mx << '\n';
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