// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  03.05.2025

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
    cin >> n;
    vector<int> v;
    for (int i = 0, it; i < n; i++)
    {
        cin >> it;
        if (v.empty())
            v.push_back(it);
        else if (v.back() != it)
            v.push_back(it);
    }
    n = v.size();
    if (n == 1)
    {
        cout << 1 << '\n';
        return;
    }
    int ans = 1, up = 0, dw = 0;
    for (int i = 1; i < n; i++)
    {
        if (v[i] > v[i - 1])
        {
            if (dw)
                ans++;
            dw = 0;
            up = 1;
        }
        else if (v[i] < v[i - 1])
        {
            dw = 1;
            up = 0;
        }
    }
    if (dw && v[n - 1] > v[n - 2])
        ans++;
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