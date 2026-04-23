// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  09.02.2025

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
    int ls, fs = inf, fl = 0;
    for (int i = 0; i + 1 < s.size(); i++)
    {
        int x = (s[i] - '0') + (s[i + 1] - '0');
        if (x > 9)
        {
            fl = 1;
            ls = i;
        }
        else
            fs = min(fs, i);
    }
    string ans;
    if (fl == 0)
    {
        int x = fs;
        for (int i = 0; i < x; i++)
            ans.push_back(s[i]);
        int y = s[fs] - '0' + s[fs + 1] - '0';
        ans += to_string(y);
        for (int i = x + 2; i < s.size(); i++)
            ans.push_back(s[i]);
        // dbg(y);
    }
    else
    {
        int x = ls;
        for (int i = 0; i < ls; i++)
            ans.push_back(s[i]);
        int y = (s[ls] - '0') + (s[ls + 1] - '0');
        ans += to_string(y);
        for (int i = ls + 2; i < s.size(); i++)
            ans.push_back(s[i]);
    }
    cout << ans << '\n';
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