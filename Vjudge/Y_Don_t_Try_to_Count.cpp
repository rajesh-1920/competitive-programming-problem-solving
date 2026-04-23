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
    int n, m;
    string t, s;
    cin >> n >> m >> t >> s;
    int cnt = 0;
    while (true)
    {
        if (s.size() <= t.size())
        {
            for (int i = 0; i < t.size(); i++)
            {
                int fl = 1;
                if (t[i] == s[0])
                {
                    for (int j = 0; j < s.size(); j++)
                        if (i + j < t.size())
                        {
                            if (s[j] != t[i + j])
                            {
                                fl = 0;
                                break;
                            }
                        }
                        else
                        {
                            fl = 0;
                            break;
                        }
                    if (fl)
                    {
                        cout << cnt << '\n';
                        return;
                    }
                }
            }
        }
        t += t;
        cnt++;
        if (cnt > 10)
            break;
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