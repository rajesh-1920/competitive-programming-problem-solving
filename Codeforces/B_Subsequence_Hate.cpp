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
    string s;
    cin >> s;
    if (s.size() < 3)
    {
        cout << 0 << '\n';
        return;
    }
    int ans = s.size();
    vector<int> c0(ans, 0), c1(ans, 0);
    for (int i = 0; i < s.size(); i++)
    {
        if (i)
            c0[i] = c0[i - 1], c1[i] = c1[i - 1];
        if (s[i] == '0')
            c0[i]++;
        else
            c1[i]++;
    }
    for (int i = 0; i < s.size(); i++)
    {
        int t = c0[i] + (c1[s.size() - 1] - c1[i]);
        ans = min(ans, t);
        t = c1[i] + (c0[s.size() - 1] - c0[i]);
        ans = min(ans, t);
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