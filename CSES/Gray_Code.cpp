// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  31.10.2025

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
vector<string> ok(int n)
{
    if (n == 1)
        return {"0", "1"};
    vector<string> res, temp = ok(n - 1);
    for (auto it : temp)
        res.push_back("0" + it);
    for (int i = temp.size() - 1; i >= 0; i--)
        res.push_back("1" + temp[i]);
    return res;
}
void solve(void)
{
    int n;
    cin >> n;
    vector<string> v = ok(n);
    for (auto it : v)
        cout << it << '\n';
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