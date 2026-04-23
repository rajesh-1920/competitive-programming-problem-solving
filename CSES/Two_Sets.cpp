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
void solve(void)
{
    int n;
    cin >> n;
    int ans = (n * (n + 1) / 2);
    if (ans & 1)
        cout << "NO\n";
    else
    {
        cout << "YES\n";
        set<int> st1, st2;
        for (int i = 1; i <= n; i++)
            st1.insert(i);
        ans /= 2;
        while (true)
        {
            if (st1.find(ans) != st1.end())
            {
                st2.insert(ans), st1.erase(ans);
                break;
            }
            int t = *(--st1.end());
            ans -= t;
            st1.erase(t), st2.insert(t);
        }
        cout << st1.size() << '\n';
        for (auto it : st1)
            cout << it << ' ';
        cout << '\n'
             << st2.size() << '\n';
        for (auto it : st2)
            cout << it << ' ';
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