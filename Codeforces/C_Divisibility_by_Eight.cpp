// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  27.05.2025

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
        int x = (s[i] - '0');
        if (x % 8 == 0)
        {
            cout << "YES\n";
            cout << x << '\n';
            return;
        }
        for (int j = i + 1; j < s.size(); j++)
        {
            x = (s[i] - '0') * 10 + (s[j] - '0');
            if (x % 8 == 0)
            {
                cout << "YES\n";
                cout << x << '\n';
                return;
            }
            for (int k = j + 1; k < s.size(); k++)
            {
                x = (s[i] - '0') * 100 + (s[j] - '0') * 10 + (s[k] - '0');
                if (x % 8 == 0)
                {
                    cout << "YES\n";
                    cout << x << '\n';
                    return;
                }
            }
        }
    }
    cout << "NO\n";
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