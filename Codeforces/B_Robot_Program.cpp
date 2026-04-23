// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  27.02.2025

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
    int n, x, k;
    string s;
    cin >> n >> x >> k >> s;
    for (auto it : s)
    {
        if (it == 'L')
            x--;
        else
            x++;
        if (x == 0)
            break;
        k--;
    }
    if (x != 0)
    {
        cout << 0 << '\n';
        return;
    }
    int cnt = 0, fl = 0, t = 1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'L')
            x--;
        else
            x++;
        cnt++;
        if (x == 0 && fl)
        {
            t = 0;
            break;
        }
        fl++;
    }
    // dbg(cnt);
    if (t)
        cout << 1 << '\n';
    else
        cout << (k + cnt - 1) / cnt << '\n';
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