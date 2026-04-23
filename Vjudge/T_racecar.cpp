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
    int n;
    cin >> n;
    vector<string> v(n);
    for (auto &it : v)
        cin >> it;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            string s = v[i] + v[j];
            int t = s.size() - 1, fl = 1;
            for (int x = 0; x < s.size(); x++)
            {
                if (t <= x)
                    break;
                if (s[x] != s[t])
                {
                    fl = 0;
                    break;
                }
                t--;
            }
            if (fl)
            {
                cout << "Yes\n";
                return;
            }
        }
    cout << "No\n";
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