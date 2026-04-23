// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  25.03.2025

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
    int n;
    string s;
    cin >> n >> s;
    int a = 0, b = 0;
    int cnt = 10, xx = 1;
    while (cnt--)
    {
        int ff = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] != s[n - i - 1])
            {
                ff = 1;
                break;
            }
        }
        if (ff)
        {
            xx ^= 1;
            continue;
        }
        if (xx)
        {
            int fl = 1, t = 1;
            for (int i = 0; i < n; i++)
            {
                if (s[i] == '0')
                {
                    t = 0;
                    if (s[n - i - 1] == '1')
                    {
                        fl = 0;
                        s[i] = '1';
                        break;
                    }
                }
            }
            if (t)
                break;
            if (fl)
                for (int i = 0; i < n; i++)
                {
                    if (s[i] == '0')
                    {
                        s[i] = '1';
                        break;
                    }
                }
        }
        else
        {
            int fl = 1, t = 1;
            for (int i = n - 1; i >= 0; i--)
            {
                if (s[i] == '0')
                {
                    t = 0;
                    if (s[n - i - 1] == '1')
                    {
                        fl = 0;
                        s[i] = '1';
                        break;
                    }
                }
            }
            if (t)
                break;
            if (fl)
                for (int i = n - 1; i >= 0; i--)
                {
                    if (s[i] == '0')
                    {
                        s[i] = '1';
                        break;
                    }
                }
        }

        if (cnt % 2)
            a++;
        else
            b++;
    }
    if (a > b)
        cout << "BOB\n";
    else if (a < b)
        cout << "ALICE\n";
    else
        cout << "DRAW\n";
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