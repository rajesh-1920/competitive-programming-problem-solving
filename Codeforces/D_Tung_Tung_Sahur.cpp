// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  13.04.2025

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
    string s, p;
    cin >> s >> p;
    int i = 0, j = 0;
    while (i < s.size())
    {
        if (s[i] == 'L')
        {
            int cl = 0, cnt = 0;
            while (j < p.size())
            {
                if (p[j] == 'R')
                    break;
                cl++;
                j++;
            }
            while (i < s.size())
            {
                if (s[i] == 'R')
                    break;
                cnt++;
                i++;
            }
            if (cnt > cl || cnt * 2 < cl)
            {
                cout << "NO\n";
                return;
            }
        }
        else
        {
            int cl = 0, cnt = 0;
            while (j < p.size())
            {
                if (p[j] == 'L')
                    break;
                cl++;
                j++;
            }
            while (i < s.size())
            {
                if (s[i] == 'L')
                    break;
                cnt++;
                i++;
            }
            if (cnt > cl || cnt * 2 < cl)
            {
                cout << "NO\n";
                return;
            }
        }
    }
    if (i == s.size() && j == p.size())
        cout << "YES\n";
    else
        cout << "NO\n";
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