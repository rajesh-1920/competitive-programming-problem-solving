// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  19.10.2025

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
    int n, m;
    cin >> n >> m;
    if (n > m)
    {
        vector<int> v;
        set<int> st;
        int ans = 1;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            x %= m;
            if (st.find(x) != st.end())
                ans = 0;
            st.insert(x);
        }
        for (auto it : st)
            v.push_back(it);
        n = v.size();
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                ans = (ans * (v[j] - v[i])) % m;
        cout << ans << '\n';
    }
    else
    {
        vector<int> v(n);
        for (auto &it : v)
            cin >> it;
        sort(all(v));
        int ans = 1;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                ans = (ans * (v[j] - v[i])) % m;
        cout << ans << '\n';
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