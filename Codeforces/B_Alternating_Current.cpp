// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  27.10.2025

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
void solve(void)
{
    string s;
    cin >> s;
    if (s.size() & 1)
    {
        cout << "NO\n";
        return;
    }
    set<int> pl, mn;
    for (int i = 0; i < s.size(); i++)
        s[i] == '+' ? pl.insert(i) : mn.insert(i);
    while (pl.size() && mn.size())
    {
        if (pl.size() & 1 || mn.size())
        {
            cout << "NO\n";
            return;
        }
        int p = (*pl.begin());
    }
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