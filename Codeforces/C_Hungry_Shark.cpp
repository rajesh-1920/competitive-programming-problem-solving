// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  13.04.2025

#include <bits/stdc++.h>
using namespace std;
//----------------------------(definition section)-----------------------------------------
#define dbg(x) cout << #x << " = " << x << '\n'
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
template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>; // multiple value
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // single
// must use ll
// ll pos = st.order_of_key(5);
// ll val = *st.find_by_order(2);
//-----------------------------------------------------------------------------------------
void solve(void)
{
    int n;
    cin >> n;
    ordered_set<int> st, pre;
    vector<int> v(n), sum;
    for (auto &it : v)
    {
        cin >> it;
        sum.push_back(it);
        st.insert(it);
    }
    sort(all(sum));
    for (int i = 1; i < n; i++)
        sum[i] = sum[i - 1] + (*st.find_by_order(i));

    for (int i = 0; i < n; i++)
    {
        int ans = v[i] - 1;
        pre.insert(v[i]);
        int t = st.order_of_key(v[i]);
        if (t)
            ans += sum[t - 1];
        ans += (n - t - 1) * (v[i] - 1);

        int tt = pre.size() - pre.order_of_key(v[i]);
        ans += tt;

        cout << ans << ' ';
    }
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