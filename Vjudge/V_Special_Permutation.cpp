// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  22.03.2025

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
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> v(n);
    int t = n, pa, pb;
    for (int i = 0; i < n; i++)
    {
        v[i] = t--;
        if (v[i] == a)
            pa = i;
        if (v[i] == b)
            pb = i;
    }
    if ((pa >= n / 2 && pb >= n / 2) || (pa < n / 2 && pb < n / 2))
    {
        cout << -1 << '\n';
        return;
    }
    if (pa >= n / 2 && pb < n / 2)
        swap(v[pa], v[pb]);

    int mx = 0;
    for (int i = n / 2; i < n; i++)
        mx = max(mx, v[i]);
    int mn = inf;
    for (int i = 0; i < n / 2; i++)
        mn = min(mn, v[i]);
    if (mn != a || mx != b)
    {
        cout << -1 << '\n';
        return;
    }
    for (auto it : v)
        cout << it << ' ';
    cout << '\n';
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