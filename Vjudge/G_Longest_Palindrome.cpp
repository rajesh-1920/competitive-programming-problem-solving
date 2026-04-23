// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  17.03.2025

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
    cin >> s;
    for (int t = s.size(); t >= 0; t--)
    {
        for (int i = 0; i + t < s.size(); i++)
        {
            int l = i, r = i + t;
            int fl = 1;
            while (l < r)
            {
                if (s[l] != s[r])
                {
                    fl = 0;
                    break;
                }
                l++, r--;
            }
            if (fl)
            {
                cout << t + 1 << '\n';
                return;
            }
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
    // cin >> test;
    for (T = 1; T <= test; T++)
    {
        // cout << "Case " << T << ": ";
        solve();
    }
    return 0;
}