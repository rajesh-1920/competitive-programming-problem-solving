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
    string s[3];
    cin >> s[0] >> s[1] >> s[2];
    for (int i = 0; i < 3; i++)
    {
        if (s[0][i] == s[1][i] && s[1][i] == s[2][i] && s[1][i] != '.')
        {
            cout << s[1][i] << '\n';
            return;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        if (s[i][0] == s[i][1] && s[i][1] == s[i][2] && s[i][1] != '.')
        {
            cout << s[i][1] << '\n';
            return;
        }
    }
    if (s[0][0] == s[1][1] && s[1][1] == s[2][2] && s[1][1] != '.')
    {
        cout << s[1][1] << '\n';
        return;
    }
    if (s[2][0] == s[1][1] && s[1][1] == s[0][2] && s[1][1] != '.')
    {
        cout << s[1][1] << '\n';
        return;
    }
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