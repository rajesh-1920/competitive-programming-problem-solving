// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  16.06.2025

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
    int ans = 0;
    for (int i = 0; i < 26; i++)
    {
        vector<int> v;
        int cnt = 0;
        v.push_back(0);
        char ch = 'a' + i;
        if (s[0] == ch)
        {
            int c = 0, fl = 0;
            for (auto it : s)
            {
                if (fl)
                {
                    if (it == ch)
                        cnt++;
                    else
                        cnt = 0;
                    ans = max(ans, c + cnt);
                }
                else
                {
                    if (it == ch)
                        c++;
                    else
                        fl = 1;
                    ans = max(ans, c);
                }
            }
        }
        else
        {
            for (auto it : s)
            {
                if (it == ch)
                    cnt++;
                else
                    cnt = 0;
                ans = max(ans, cnt);
            }
        }
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