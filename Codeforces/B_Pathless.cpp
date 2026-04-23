// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  31.07.2025

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
//------------------------------(solve)----------------------------------------------------
void solve(void)
{
    int n, s;
    cin >> n >> s;
    vector<int> v(n);
    int sum = 0;
    int c1 = 0, c0 = 0, c2 = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
        sum += v[i];
        c1 += v[i] == 1;
        c0 += v[i] == 0;
        c2 += v[i] == 2;
    }

    if (sum > s)
    {
        for (auto it : v)
            cout << it << " ";
        cout << '\n';
    }
    else if (s % 2 == 0 && c1 % 2 == 1 && (c1 > 1||s==4))
    {
        while (c0--)
            cout << 0 << ' ';
        while (c2--)
            cout << 2 << ' ';
        while (c1--)
            cout << 1 << ' ';
        cout << '\n';
    }
    else if (s % 2 == 1 && c1 % 2 == 0 && (s - sum == 1))
    {
        while (c0--)
            cout << 0 << ' ';
        while (c2--)
            cout << 2 << ' ';
        while (c1--)
            cout << 1 << ' ';
        cout << '\n';
    }
    else
        cout << -1 << '\n';
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