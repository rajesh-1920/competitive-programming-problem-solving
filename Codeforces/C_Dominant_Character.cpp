// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  23.02.2025

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
    for (int i = 0; i + 1 < n; i++)
    {
        if (s[i] == 'a' && s[i + 1] == 'a')
        {
            cout << 2 << '\n';
            return;
        }
    }
    for (int i = 0; i + 2 < n; i++)
    {
        if (s[i] == 'a' && s[i + 2] == 'a')
        {
            cout << 3 << '\n';
            return;
        }
    }
    for (int i = 0; i + 3 < n; i++)
    {
        if (s[i] == 'a' && s[i + 3] == 'a' && s[i + 1] != s[i + 2])
        {
            cout << 4 << '\n';
            return;
        }
    }
    for (int i = 0; i + 6 < n; i++)
    {
        if (s[i] == 'a' && s[i + 3] == 'a' && s[i + 6] == 'a')
            if (s[i + 1] == 'c' && s[i + 2] == 'c')
                if (s[i + 4] == 'b' && s[i + 5] == 'b')
                {
                    cout << 7 << '\n';
                    return;
                }
        if (s[i] == 'a' && s[i + 3] == 'a' && s[i + 6] == 'a')
            if (s[i + 1] == 'b' && s[i + 2] == 'b')
                if (s[i + 4] == 'c' && s[i + 5] == 'c')
                {
                    cout << 7 << '\n';
                    return;
                }
    }
    cout << -1 << '\n';
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