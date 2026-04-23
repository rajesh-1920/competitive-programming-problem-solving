// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  13.04.2025

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
    int n, l, r;
    cin >> n >> l >> r;
    if (n == 2)
    {
        if (l + 2 > r)
            cout << -1 << '\n';
        else
            cout << l << ' ' << l + 2 << '\n';
        return;
    }
    vector<int> v;
    v.push_back(l + 2);
    v.push_back(l);
    v.push_back(l + 3);
    int pre = l + l + 3;
    while (v.size() < n)
    {
        pre++;
        v.push_back(pre - v.back());
    }
    for (int i = 0; i < n; i++)
        if (v[i] > r)
        {
            cout << -1 << '\n';
            return;
        }
    // map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << ' ';
        // mp[v[i] + v[i + 1]]++;
        //  if (mp[v[i] + v[i + 1]] > 1)
        //  {
        //      dbg(i);
        //  }
    }
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