// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  10.08.2025

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
    vector<set<int>> v(n + 5);
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x].insert(y);
        v[y].insert(x);
    }
    multiset<int> st;
    int mx = 0;
    for (int i = 1; i <= n; i++)
    {
        int z = v[i].size();
        mx = max(mx, z);
        st.insert(v[i].size());
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (v[i].size() == mx)
        {
            int t = v[i].size();
            st.erase(st.find(mx));
            for (auto it : v[i])
            {
                st.erase(st.find(v[it].size()));
                st.insert(v[it].size() - 1);
            }
            t += ((*--(st.end())) - 1);
            for (auto it : v[i])
            {
                st.erase(st.find(v[it].size() - 1));
                st.insert(v[it].size());
            }
            st.insert(mx);
            ans = max(ans, t);
        }
    }
    cout << ans << '\n';
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