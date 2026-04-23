// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  21.08.2025

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
    vector<int> v(n), ans(2 * n, -1);
    for (auto &it : v)
        cin >> it;
    set<int> st;
    for (int i = 1; i <= 2 * n; i++)
    {
        st.insert(i);
        if (i & 1)
            ans[i] = v[i / 2];
    }
    for (auto it : v)
        if (st.find(it) != st.end())
            st.erase(it);
        else
        {
            cout << -1 << '\n';
            return;
        }
    int i = 1;
    while (st.size())
    {
        if (st.upper_bound(ans[i]) == st.end())
        {
            cout << -1 << '\n';
            return;
        }
        ans[i - 1] = *(st.upper_bound(ans[i]));
        st.erase(st.upper_bound(ans[i]));
        if (ans[i] < ans[i - 1])
            swap(ans[i], ans[i - 1]);
        i += 2;
    }
    for (auto it : ans)
        cout << it << ' ';
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