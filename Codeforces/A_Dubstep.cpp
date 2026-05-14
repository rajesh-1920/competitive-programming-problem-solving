// Author:  Rajesh Biswas
// CF    :  rajesh_1920
// Date  :  12.05.2026

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
    string s, ans;
    cin >> s;
    int i = 0;
    while (i < s.size())
    {
        if (i + 2 < s.size() && s[i] == 'W' && s[i + 1] == 'U' && s[i + 2] == 'B')
        {
            i += 3;
            if (!ans.empty() && ans.back() != ' ')
                ans.push_back(' ');
        }
        else
        {
            ans.push_back(s[i]);
            i++;
        }
    }
    reverse(all(ans));
    while (!ans.empty() && ans.back() == ' ')
        ans.pop_back();
    reverse(all(ans));
    cout << ans << '\n';
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