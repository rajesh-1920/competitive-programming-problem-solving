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
    int n, k;
    cin >> n >> k;
    set<int> st;
    vector<int> v(n), t;
    for (auto &it : v)
    {
        cin >> it;
    }
    k--;
    for (int i = 0; i < n; i++)
    {
        if (v[i] >= v[k])
            st.insert(v[i]);
    }
    for (auto it : st)
        t.emplace_back(it);
    int tim = 0;
    for (int i = 1; i < t.size(); i++)
    {
        int need = tim + t[i] - t[i - 1];
        if (need >t[i - 1])
        {
            // dbg(v[i]);
            // dbg(need);
            cout << "NO\n";
            return;
        }
        tim = need;
    }
    cout << "YES\n";
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