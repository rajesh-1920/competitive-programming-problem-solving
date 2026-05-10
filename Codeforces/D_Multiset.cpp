// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  10.05.2026

#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> order_set;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k, x;
    cin >> n >> k;
    order_set st;
    while (n--)
    {
        cin >> x;
        st.insert(x);
    }
    while (k--)
    {
        cin >> n;
        if (x > 0)
            st.insert(x);
        else
        {
            x *= -1;
            x--;
            st.erase(st.upper_bound((*st.find_by_order(x))));
        }
    }
    if (st.empty())
        cout << 0 << '\n';
    else
        cout << (*st.find_by_order(0)) << '\n';
    return 0;
}