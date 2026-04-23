// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  11.09.2025

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
bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
{
    return a.sc.fi > b.sc.fi;
}
void solve(void)
{
    int n;
    cin >> n;
    vector<pair<int, pair<int, int>>> v(n);
    for (auto &it : v)
        cin >> it.fi;
    int i = 0;
    for (auto &it : v)
        cin >> it.sc.fi, it.sc.sc = i++;
    sort(all(v));
    vector<int> ans(n, 0);
    set<int> st, sa;
    st.insert(v.back().sc.fi);
    sa.insert(v.back().fi);
    ans[v.back().sc.sc] = 1;
    v.pop_back();

    sort(all(v), cmp);
    for (auto it : v)
    {
        if (st.upper_bound(it.sc.fi) != st.begin() || sa.upper_bound(it.fi) != sa.begin())
        {
            st.insert(it.sc.fi);
            sa.insert(it.fi);
            ans[it.sc.sc] = 1;
        }
        //dbg(it.sc.fi);
    }
    for (auto it : ans)
        cout << it;
    cout << '\n';
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