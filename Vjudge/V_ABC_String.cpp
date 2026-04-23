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
    if (s[0] == s[s.size() - 1])
    {
        cout << "NO\n";
        return;
    }
    for (int i = 1; i < s.size(); i++)
        if (s[0] == s[i])
            s[i] = '(';
    s[0] = '(';
    for (int i = 1; i < s.size(); i++)
        if (s[i] == s[s.size() - 1])
            s[i] = ')';
    string t = s;
    for (int i = 0; i < s.size(); i++)
        if (s[i] != ')')
            s[i] = '(';
    for (int i = 0; i < s.size(); i++)
        if (t[i] != '(')
            t[i] = ')';
    int fl = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            fl++;
        else
            fl--;
        if (fl < 0)
        {
            break;
        }
    }
    if (fl == 0)
    {
        cout << "YES\n";
        return;
    }
    fl = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (t[i] == '(')
            fl++;
        else
            fl--;
        if (fl < 0)
        {
            cout << "NO\n";
            return;
        }
    }
    if (fl != 0)
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
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