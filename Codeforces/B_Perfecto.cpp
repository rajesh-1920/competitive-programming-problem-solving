// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  28.02.2025

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
    int t = (n + 1) * n / 2;
    int sq = sqrtl(t);
    for (int i = sq - 5; i <= sq + 5; i++)
    {
        if (i * i == t)
        {
            cout << -1 << '\n';
            return;
        }
    }
    vector<int> ans;
    for (int i = 2; i <= n; i += 2)
        ans.push_back(i);
    for (int i = 1; i <= n; i += 2)
        ans.push_back(i);
    int to = 0;
    for (int i = 0; i + 1 < n; i++)
    {
        int tt = to + ans[i];
        int sqr = sqrt(tt);
        if (sqr * sqr == tt)
            swap(ans[i], ans[i + 1]);
        to += ans[i];
    }
    for (auto it : ans)
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