// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  18.10.2025

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
bool ok(int len, vector<int> &v)
{
    int n = v.size();
    set<pair<int, int>> st;
    for (int i = 0; i < n; i++)
        st.insert({v[i], i});
    int t = 0;
    while (st.size())
    {
        int x = (*st.begin()).sc;
        if (v[x] > len)
            return false;
        st.erase(st.begin());
        int temp = x;
        while (x < n && abs(v[x] - v[x + 1]) <= len)
        {
            if (st.empty())
                break;
            x++;
            st.erase({v[x], x});
        }
        x = temp;
        while (x && abs(v[x] - v[x - 1]) <= len)
        {
            if (st.empty())
                break;
            x--;
            st.erase({v[x], x});
        }
    }
    if (st.size())
        return false;
    return true;
}
void solve(void)
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &it : v)
        cin >> it;
    int ans = 0, l = 0, r = MOD;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (ok(m, v))
            ans = m, r = m - 1;
        else
            l = m + 1;
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
        cout << "Case #" << T << ": ";
        solve();
    }
    return 0;
}