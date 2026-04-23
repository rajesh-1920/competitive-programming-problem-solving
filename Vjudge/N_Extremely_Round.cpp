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
vector<int> v;
void ok()
{
    int i = 1;
    for (int i = 1; i < 10; i++)
        v.push_back(i);
    int t = 0;
    while (true)
    {
        v.push_back(v[t] * 10);
        t++;
        if (v.back() > 99999999)
            break;
    }
}
void solve(void)
{
    int n;
    cin >> n;
    for (int i = 0;; i++)
    {
        if (v[i] > n)
        {
            cout << i << '\n';
            return;
        }
    }
}
//-----------------------------------------------------------------------------------------
signed main()
{
    // cout << fixed << showpoint << setprecision(10);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1, T;
    ok();
    cin >> test;
    for (T = 1; T <= test; T++)
    {
        // cout << "Case " << T << ": ";
        solve();
    }
    return 0;
}