// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  17.10.2025

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
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &it : v)
        cin >> it;
    vector<int> res;
    int x = 1;
    while (res.size() < k)
    {
        if (x != v[v.size() - 1] && x != v[v.size() - 2])
            res.push_back(x), v.push_back(x);
        x++;
        if (x > n)
            x = 1;
    }
    for (auto it : res)
        cout << it << " ";
    cout << "\n";
}
//-----------------------------------------------------------------------------------------
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1, T;
    cin >> test;
    for (T = 1; T <= test; T++)
    {
        solve();
    }
    return 0;
}