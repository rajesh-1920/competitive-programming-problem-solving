// Author:  Rajesh Biswas
// CF    :  rajesh_1920
// Date  :  04.06.2026

#include <bits/stdc++.h>
using namespace std;
//----------------------------(definition section)-----------------------------------------
#define Dbg(x) cout << #x << " = " << x << '\n'
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
    vector<int> v(s.size(), 0);
    stack<int> stc;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == '(')
            stc.push(i);
        else if (!stc.empty())
        {
            v[i] = 1, v[stc.top()] = 1;
            stc.pop();
        }
    int cn = 0, cnt = 0, ans = 0;
    for (auto &it : v)
        if (it)
        {
            cn++;
            cnt = max(cn, cnt);
        }
        else
            cn = 0;
    cn = 0;
    for (auto &it : v)
        if (it)
        {
            cn++;
            ans += cn == cnt;
        }
        else
            cn = 0;
    if (cnt == 0)
        ans = 1;
    cout << cnt << ' ' << ans << '\n';
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