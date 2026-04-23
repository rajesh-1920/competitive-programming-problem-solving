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
    int n, x;
    cin >> n >> x;
    if (x == 0)
    {
        if (n == 1)
            cout << -1 << '\n';
        else if (n & 1)
            cout << 3 + n << '\n';
        else
            cout << n << '\n';
        return;
    }
    if (x == 1)
    {
        if (n & 1)
            cout << n << '\n';
        else
            cout << n + 3 << '\n';
        return;
    }
    string s = "";
    vector<int> v;
    int t = 1, temp = x;
    while (x)
    {
        if (x & 1)
            s.push_back('1'), v.push_back(t);
        else
            s.push_back('0');
        x /= 2;
        t *= 2;
    }
    int ans;
    if (v.size() >= n)
        ans = temp;
    else
    {
        ans = temp + n - v.size();
        if ((n - v.size()) & 1)
            ans++;
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