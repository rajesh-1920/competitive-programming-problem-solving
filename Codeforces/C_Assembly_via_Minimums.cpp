// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  18.05.2025

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
const int inf = 1e9;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;
//-----------------------------------------------------------------------------------------
void solve(void)
{
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; 2 * i < (n * (n - 1)); i++)
    {
        int x;
        cin >> x;
        mp[x]++;
    }
    vector<int> v;
    while (v.size() < n)
    {
        if (mp.empty())
        {
            v.push_back(inf);
            continue;
        }
        int t = (*mp.begin()).fi;
        v.push_back(t);
        if (mp[t] <= n - v.size())
            mp.erase(t);
        else
            mp[t] = mp[t] - (n - v.size());
    }

    for (auto it : v)
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