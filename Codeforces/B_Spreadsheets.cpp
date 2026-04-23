// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  31.07.2025

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
    string s;
    cin >> s;
    int cat = 0, as = 0;
    for (int i = s.size() - 1; i > 0; i--)
    {
        if (s[i] == 'C')
            as = 1;
        if (s[i] >= '0' && s[i] <= '9')
            if (as)
            {
                cat = 1;
                break;
            }
    }
    if (cat == 1)
    {
        int n = 0, fl = 0;
        for (auto it : s)
        {
            if (it >= '0' && it <= '9')
                n = n * 10 + it - '0', fl = 1;
            else if (fl == 1)
                break;
        }
        int col = 0;
        fl = 0;
        for (auto it : s)
        {
            if (it >= '0' && it <= '9')
            {
                if (fl == 0)
                    fl = 1;
                else if (fl == 2)
                    col = col * 10 + it - '0';
            }
            else if (fl == 1)
                fl = 2;
        }
        string ans = "";
        int ffff = 1;
        while (col > 0)
        {
            int t = col % 26;
            col = col / 26;
            if (t == 0)
                t = 26, col--;
            char ch = 'A' + t - 1;
            ans.push_back(ch);
        }
        reverse(all(ans));
        cout << ans << n << '\n';
    }
    else
    {
        string t = "R";
        for (auto it : s)
            if (it >= '0' && it <= '9')
                t.push_back(it);
        cout << t << 'C';
        int col = 0;
        for (auto it : s)
            if (it >= '0' && it <= '9')
                break;
            else
            {
                int tt = it - 'A' + 1;
                col = col * 26 + tt;
            }
        cout << col << '\n';
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