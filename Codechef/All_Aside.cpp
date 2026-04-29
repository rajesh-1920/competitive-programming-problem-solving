// Author:  Rajesh Biswas
// CF    :  rajesh_1920
// Date  :  29.04.2026

#include <bits/stdc++.h>
using namespace std;
//----------------------------(definition section)-----------------------------------------
#define dbg(x) cout << #x << " = " << x << '\n';
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
    int n;
    string s;
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            int cnt = 0;
            for (int j = i; j < n; j++)
            {
                if (s[j] == '0')
                    break;
                cnt = j;
            }
            for (int j = i; j < cnt; j++)
                s[j] = '0';
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            int cnt = 0;
            for (int j = i + 1; j < n; j++)
            {
                if (s[j] == '1')
                    break;
                cnt++;
            }
            if (cnt > 1)
            {
                s[i] = '0';
                s[i + cnt - 1] = '1';
            }
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
        // cout << "Case #" << T << ": ";
        solve();
    }
    return 0;
}