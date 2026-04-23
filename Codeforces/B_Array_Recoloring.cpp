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
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if (v[mx] < v[i])
            mx = i;
    }
    int ans = v[mx];
    if (k == 1 && mx != 0 && mx != n - 1)
    {
        ans += max(v[0], v[n - 1]);
        cout << ans << '\n';
        return;
    }
    priority_queue<int> pl, pr;
    for (int i = mx + 1; i < n; i++)
        pr.push(v[i]);
    for (int i = mx - 1; i >= 0; i--)
        pl.push(v[i]);
    while (k--)
    {
        if (pl.empty())
            ans += pr.top(), pr.pop();
        else if (pr.empty())
            ans += pl.top(), pl.pop();
        else
        {
            if (pl.top() < pr.top())
                ans += pr.top(), pr.pop();
            else
                ans += pl.top(), pl.pop();
        }
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