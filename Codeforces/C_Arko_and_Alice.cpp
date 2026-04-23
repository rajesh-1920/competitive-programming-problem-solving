// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  11.04.2025

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
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != '1' && s[i] != '4')
        {
            cout << "NO\n";
            return;
        }
        if (i + 2 < s.size())
        {
            if (s[i] == '4' && s[i + 1] == '4' && s[i + 2] == '4')
            {
                // dbg(i);
                cout << "NO\n";
                return;
            }
        }
    }
    if (s[0] != '1')
        cout << "NO\n";
    else
        cout << "YES\n";
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