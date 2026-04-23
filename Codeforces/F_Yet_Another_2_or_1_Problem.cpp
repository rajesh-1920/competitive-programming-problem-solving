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
bool is(string &s)
{
    for (int i = 0; i < s.size(); i++)
    {
        int t = s.size() - i;
        if (t == 0)
            return true;
        if (s[i] != s[t - 1])
            return false;
    }
    return true;
}
void solve(void)
{
    int n, k;
    string s;
    cin >> n >> k >> s;
    int fl = 0;
    while (k--)
    {
        if (is(s))
        {
            s.push_back(s.back());
            fl++;
        }
        else
        {
            s = s.substr(0, (s.size() / 2));
            fl = 0;
        }
        if (fl == 2)
        {
            while (k--)
            {
                s.push_back(s.back());
            }
            break;
        }
    }
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