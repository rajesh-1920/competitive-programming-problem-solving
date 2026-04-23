// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  18.05.2025

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
    reverse(all(s));
    int hate = 0, fl = -1;
    for (int i = 0; i < s.size();)
    {
        if (s[i] >= '5')
        {
            s[i] = '0';
            fl = i;
            i++;
            while (i < s.size())
            {
                if (s[i] != '9')
                    break;
                s[i] = '0';
                i++;
            }
            if (i == s.size())
                s.push_back('1');
            else
                s[i] = s[i] + 1;
        }
        else
            i++;
    }
    while (fl >= 0)
    {
        s[fl] = '0';
        fl--;
    }
    reverse(all(s));
    cout << s << '\n';
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