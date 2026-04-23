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
    int n;
    cin >> n;
    vector<int> v(n), zero;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if (v[i] == 0)
            zero.push_back(i);
    }
    vector<pair<int, int>> ans;
    sort(all(zero));
    if (zero.size() == 0)
        ans.push_back({1, n});
    else if (zero.size() == 1)
    {
        int t = zero[0] + 1;
        if (t <= 2)
        {
            ans.push_back({1, 2});
            ans.push_back({1, n - 1});
        }
        else
        {
            ans.push_back({t - 1, t});
            ans.push_back({1, n - 1});
        }
    }
    else if (zero.size() == 2)
    {
        int t = zero[0] + 1;
        int t1 = zero[1] + 1;
        if (t + 1 == t1)
        {
            ans.push_back({t, t1});
            ans.push_back({1, n - 1});
        }
        else
        {
            if (t == 1)
            {
                ans.push_back({1, 2});
                ans.push_back({2, n - 1});
                ans.push_back({1, 2});
            }
            else
            {
                ans.push_back({1, t});
                ans.push_back({2, n - t + 1});
                ans.push_back({1, 2});
            }
        }
    }
    else
    {
        int t = zero[0] + 1;
        if (t == 1)
        {
            ans.push_back({1, 2});
            ans.push_back({2, n - 1});
            ans.push_back({1, 2});
        }
        else
        {
            ans.push_back({1, t});
            ans.push_back({2, n - t + 1});
            ans.push_back({1, 2});
        }
    }
    cout << ans.size() << '\n';
    for (auto it : ans)
        cout << it.fi << ' ' << it.sc << '\n';
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