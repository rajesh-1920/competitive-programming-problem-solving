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
    int h, m;
    char ch;
    cin >> h >> ch >> m;
    string t1 = "00", t2 = "00";
    while (true)
    {
        if (m == 0 && h == 0)
        {
            t2 = t1 = "00";
            break;
        }
        if (h > 9 && m > 9)
        {
            t1 = to_string(h);
            t2 = to_string(m);
            if (t1[0] == t1[1] && t1[0] == t2[0] && t1[0] == t2[1])
                break;
        }
        m++;
        if (m == 60)
            m = 0, h++;
        if (h == 24)
            h = 0;
    }
    cout << t1 << ch << t2 << '\n';
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