// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  11.02.2025

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
    map<int, int> mp;
    vector<int> v(n);
    for (auto &it : v)
    {
        cin >> it;
        mp[it]++;
    }
    int fl = 1;
    for (auto it : mp)
    {
        if (it.sc & 1)
        {
            fl = 0;
            break;
        }
    }
    if (fl)
    {
        cout << "Yes\n";
        return;
    }
    for (int i = 1; i <= 2 * n; i++)
    {
        if (mp[i] == 0)
            continue;
        if (mp[i] < 2)
        {
            cout << "No\n";
            return;
        }
        mp[i] -= 2;
        mp[i + 1] += mp[i];
    }
    cout << "Yes\n";
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