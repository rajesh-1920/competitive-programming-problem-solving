// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  28.08.2025

#include <bits/stdc++.h>
using namespace std;
//----------------------------(definition section)-----------------------------------------
#define dbg(x) cout << #x << " = " << x << '\n';
#define int long long int
#define fi first
#define sc second

#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()

const double eps = 1e-1;
const int inf = 9e16 + 7;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;
//------------------------------(solve)----------------------------------------------------
void solve(void)
{
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for (auto &it : v)
        cin >> it;
    sort(rall(v));
    long double temp = 0;
    for (int i = 1; i <= n; i++)
    {
        x -= (v[i - 1] / i);
        if (v[i - 1] % i)
        {
            long double x1 = i, x2 = v[i - 1] % i;
            temp += (x2 / x1);
        }
        if (x <= 0)
        {
            cout << "YES\n";
            return;
        }
    }
    double xx = x;
    xx -= temp;
    if (xx <= 0.0)
        cout << "YES\n";
    else
        cout << "NO\n";
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