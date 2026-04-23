// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  11.09.2025

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
int simulate(vector<int> a, const vector<int> &tar, int n)
{
    int ops = 0;
    for (int i = 0; i < n - 1; i++)
        if (a[i] != tar[i])
        {
            a[i] ^= 1;
            a[i + 1] ^= 1;
            if (i + 2 < n)
                a[i + 2] ^= 1;
            ops++;
        }
    if (a[n - 1] != tar[n - 1])
        return -1;
    return ops;
}

void solve()
{
    int n;
    string s;
    cin >> n >> s;

    vector<int> tar(n), a(n);
    for (int i = 0; i < n; i++)
        tar[i] = i % 2, a[i] = s[i] - '0';

    int ans1 = simulate(a, tar, n);
    a[0] ^= 1;
    if (n > 1)
        a[1] ^= 1;
    int ans2 = simulate(a, tar, n);
    if (ans2 != -1)
        ans2++;

    if (ans1 == -1 && ans2 == -1)
        cout << -1 << '\n';
    else if (ans1 == -1)
        cout << ans2 << '\n';
    else if (ans2 == -1)
        cout << ans1 << '\n';
    else
        cout << min(ans1, ans2) << '\n';
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