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
    int n, x, sum = 0;
    cin >> n >> x;
    vector<int> v(n - 1);
    for (auto &it : v)
    {
        cin >> it;
        sum += it;
    }
    sort(all(v));
    for (int i = 0; i <= 100; i++)
    {
        int t = sum;
        if (i < v[0])
        {
            sum -= v.back();
            if (sum >= x)
            {
                cout << i << '\n';
                return;
            }
        }
        else if (i > v.back())
        {
            sum -= v[0];
            if (sum >= x)
            {
                cout << i << '\n';
                return;
            }
        }
        else
        {
            sum -= v.back();
            sum -= v[0];
            sum += i;
            if (sum >= x)
            {
                cout << i << '\n';
                return;
            }
        }
        sum = t;
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
    // cin >> test;
    for (T = 1; T <= test; T++)
    {
        // cout << "Case " << T << ": ";
        solve();
    }
    return 0;
}