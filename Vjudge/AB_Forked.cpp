// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  17.03.2025

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
    int a, b, x, y, l, r;
    cin >> a >> b >> x >> y >> l >> r;
    vector<pair<int, int>> v;
    v.push_back({x + a, y + b});
    v.push_back({x + a, y - b});
    v.push_back({x - a, y + b});
    v.push_back({x - a, y - b});
    v.push_back({x + b, y + a});
    v.push_back({x + b, y - a});
    v.push_back({x - b, y + a});
    v.push_back({x - b, y - a});
    set<pair<int, int>> st;
    for (auto it : v)
    {
        if (it.fi + a == l && it.sc + b == r)
            st.insert({it.fi, it.sc});
        if (it.fi - a == l && it.sc + b == r)
            st.insert({it.fi, it.sc});
        if (it.fi + a == l && it.sc - b == r)
            st.insert({it.fi, it.sc});
        if (it.fi - a == l && it.sc - b == r)
            st.insert({it.fi, it.sc});
        if (it.fi + b == l && it.sc + a == r)
            st.insert({it.fi, it.sc});
        if (it.fi - b == l && it.sc + a == r)
            st.insert({it.fi, it.sc});
        if (it.fi + b == l && it.sc - a == r)
            st.insert({it.fi, it.sc});
        if (it.fi - b == l && it.sc - a == r)
            st.insert({it.fi, it.sc});
    }
    cout << st.size() << '\n';
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