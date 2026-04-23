// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  07.02.2025

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
const int MOD = 1e9 + 100;
const int N = 1e5 + 10;
//-----------------------------------------------------------------------------------------
map<int, int> mp;
void ans()
{
    mp[0] = 0;
    int cnt = 0;
    for (int a = 1; a * a <= 2 * MOD; a++)
    {
        int b = (a * a) / 2;
        int c = a * a - b;
        if (c * c == a * a + b * b && b > 0)
        {
            cnt++;
            mp[c] = cnt;
        }
    }
}
void solve(void)
{
    int n;
    cin >> n;
    auto it = mp.upper_bound(n);
    it--;
    cout << (it->sc) << '\n';
}
//-----------------------------------------------------------------------------------------
signed main()
{
    // cout << fixed << showpoint << setprecision(10);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1, T;
    cin >> test;
    ans();
    for (T = 1; T <= test; T++)
    {
        // cout << "Case " << T << ": ";
        solve();
    }
    return 0;
}