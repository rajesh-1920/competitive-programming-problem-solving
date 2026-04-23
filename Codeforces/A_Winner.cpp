// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  16.06.2025

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
    map<string, int> mp, cnt;
    int mx = -inf;
    vector<pair<string, int>> v;
    for (int i = 0; i < n; i++)
    {
        string s;
        int x;
        cin >> s >> x;
        mp[s] += x;
        v.push_back({s, x});
    }
    set<string> st;
    for (auto it : mp)
        mx = max(mx, it.sc);
    for (auto it : mp)
        if (it.sc == mx)
            st.insert(it.fi);
    for (auto it : v)
    {
        cnt[it.fi] += it.sc;
        if (cnt[it.fi] >= mx && st.find(it.fi) != st.end())
        {
            cout << it.fi << '\n';
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
    // cin >> test;
    for (T = 1; T <= test; T++)
    {
        // cout << "Case " << T << ": ";
        solve();
    }
    return 0;
}