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
    cin >> n >> m;
    vector<int> v(m);
    for (auto &it : v)
        cin >> it;
    sort(all(v));
    int ans = 0;
    int ptr = m - 1, sum = 0;
    for (int i = 0; i < m; i++)
        v[i] = min(v[i], n - 1);
    for (int i = 0; i < m; i++)
    {
        while (ptr >= 0 && (v[i] + v[ptr] >= n))
        {
            sum += v[ptr];
            ptr--;
        }
        if (ptr <= i && 2 * v[i] >= n)
            ans -= v[i] + (v[i] - n + 1);
        ans += sum + ((m - ptr - 1) * (v[i] - n + 1));
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