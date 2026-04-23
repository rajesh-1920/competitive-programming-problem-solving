// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  11.07.2025

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
//------------------------------(solve)----------------------------------------------------
void solve(void)
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &it : v)
        cin >> it;
    vector<int> b(n);
    for (auto &it : b)
        cin >> it;
    reverse(all(v));
    reverse(all(b));
    set<int> sb, sv;
    for (int i = 0; i < n; i++)
    {
        if (b[i] == v[i])
        {
            cout << (n - i) << '\n';
            return;
        }
        if (sb.find(b[i]) != sb.end() || sv.find(v[i]) != sv.end() ||
            sb.find(v[i]) != sb.end() || sv.find(b[i]) != sv.end())
        {
            cout << (n - i) << '\n';
            return;
        }
        if (i - 1 >= 0)
        {
            if (b[i] == b[i - 1] || v[i] == v[i - 1])
            {
                cout << (n - i) << '\n';
                return;
            }
            sb.insert(b[i - 1]);
            sv.insert(v[i - 1]);
        }
    }
    cout << 0 << '\n';
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