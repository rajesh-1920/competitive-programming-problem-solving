// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  06.06.2025

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
    vector<int> v(4, 0);
    for (auto it : s)
        if (it != '?')
            v[it - 'A']++;
    int ans = 0;
    if (v[0] > n)
        ans += n;
    else
        ans += v[0];
    if (v[1] > n)
        ans += n;
    else
        ans += v[1];
    if (v[2] > n)
        ans += n;
    else
        ans += v[2];
    if (v[3] > n)
        ans += n;
    else
        ans += v[3];

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