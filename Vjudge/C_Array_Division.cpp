// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  04.03.2025

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
const int N = 2e5 + 10;
//-----------------------------------------------------------------------------------------
vector<int> v(N);
int n, k;
bool pos(int x)
{
    int cnt = 1, sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (v[i] > x)
            return false;
        if (sum + v[i] > x)
        {
            cnt++;
            sum = 0;
        }
        sum += v[i];
    }
    return cnt <= k;
}
void solve(void)
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    int l = 0, ans = 0, r = inf;
    while (l < r)
    {
        int m = (l + r) / 2;
        if (pos(m))
        {
            r = m;
            ans = m;
        }
        else
            l = m + 1;
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
    // cin >> test;
    for (T = 1; T <= test; T++)
    {
        // cout << "Case " << T << ": ";
        solve();
    }
    return 0;
}