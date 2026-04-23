// Author:  Rajesh Biswas
// CF    :  rajesh_1920
// Date  :  16.01.2026

#include <bits/stdc++.h>
using namespace std;
//----------------------------(definition section)-----------------------------------------
#define dbg(x) cout << #x << " = " << x << '\n';
#define int long int
#define fi first
#define sc second

#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()

const double eps = 1e-1;
const int inf = 9e16 + 7;
const int MOD = 1e8;
const int N = 1e5 + 10;
//------------------------------(solve)----------------------------------------------------
void solve(void)
{
    string t, s = "#";
    cin >> t;
    for (auto &it : t)
        s += it, s += "#";
    int n = s.size(), C = 0, R = 0;
    vector<int> p(n, 0);
    for (int i = 0; i < n; i++)
    {
        int mir = 2 * C - i;
        if (i < R)
            p[i] = min(R - i, p[mir]);
        int a = i + p[i] + 1, b = i - p[i] - 1;
        // if (s[i] == '#')
        {
            while (a < n && b >= 0 &&
                   ((s[a] == '(' && s[b] == ')') || (s[a] == ')' && s[b] == '(') || (s[a] == '#' && s[b] == '#')))
                p[i]++, a++, b--;
            a--, b++;
            while (p[i] > 0 && ((s[a] == '(' && s[b] == ')') || (s[a] == '#' && s[b] == '#')))
                p[i]--, a--, b++;
        }
        if (i + p[i] > R)
            C = i, R = i + p[i];
    }
    int mx = 0, ans = 0;
    for (int i = 1; i + 1 < n; i++)
        if (mx < p[i] && s[i] == '#' && ((s[i - 1] == ')' && s[i + 1] == '(') || (s[i - 1] == '(' && s[i + 1] == ')')))
            mx = p[i];
    // cout << s << '\n';
    // for (auto it : p)
    //     cout << it;
    // cout << '\n';

    if (mx)
    {
        for (int i = 0; i < n; i++)
            if (mx == p[i] && s[i] == '#' &&
                ((s[i - 1] == ')' && s[i + 1] == '(') || (s[i - 1] == '(' && s[i + 1] == ')')))
                ans++;
        if (mx & 1)
            mx++;
    }
    else
        ans = 1;
    cout << mx << ' ' << ans << '\n';
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