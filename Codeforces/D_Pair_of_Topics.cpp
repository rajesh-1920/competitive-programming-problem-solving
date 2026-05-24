// Author:  Rajesh Biswas
// CF    :  rajesh_1920
// Date  :  24.05.2026

#include <bits/stdc++.h>
using namespace std;
//----------------------------(definition section)-----------------------------------------
#define dbg(x) cout << #x << " = " << x << '\n'
// #define int long long int
#define fi first
#define sc second

#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()

const double eps = 1e-1;
const int inf = 9e16 + 7;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;
//-----------------------------------------------------------------------------------------
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<long long, null_type, less_equal<long long>, rb_tree_tag, tree_order_statistics_node_update> order_set;
void solve(void)
{
    int n;
    cin >> n;
    vector<long long> v(n), vv(n);
    for (auto &it : v)
        cin >> it;
    for (auto &it : vv)
        cin >> it;
    order_set st;
    st.insert(vv.back() - v.back());
    long long ans = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        ans += st.order_of_key(v[i] - vv[i]);
        st.insert(vv[i] - v[i]);
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
    // cin >> test;
    for (T = 1; T <= test; T++)
    {
        // cout << "Case " << T << ": ";
        solve();
    }
    return 0;
}