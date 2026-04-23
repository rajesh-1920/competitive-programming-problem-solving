#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define Wrong                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

#define dbg(x) cout << #x << " = " << x << '\n';

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main()
{
    Wrong;
    ll t;
    cin >> t;
    while (t--)
    {
        ordered_set<ll> st;
        map<int, int> mp, pos;
        int n, q;
        cin >> n >> q;
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            if (mp.find(x) == mp.end())
                mp[x] = i;
        }
        int cnt = 0;
        for (auto it : mp)
            st.insert(it.second);
        for (auto it : st)
        {
            // cout << it << ' ';
            pos[it] = cnt;
            cnt++;
        }
        cnt = -1;
        while (q--)
        {
            int x;
            cin >> x;
            if (mp[x] < 0)
            {
                cout << st.order_of_key(mp[x]) + 1 << '\n';
                st.erase(st.upper_bound(mp[x]));
                mp[x] = cnt--;
                st.insert(mp[x]);
            }
            else
            {
                int init_pos = pos[mp[x]];
                int cur_pos = st.order_of_key(mp[x]);
                // for (auto it : st)
                //     cout << it << ' ';
                // dbg(mp[x]);
                // dbg(init_pos);
                // dbg(cur_pos);
                cout << mp[x] + (cur_pos - init_pos) << '\n';
                st.erase(st.upper_bound(mp[x]));
                mp[x] = cnt--;
                st.insert(mp[x]);
            }
        }
    }
    return 0;
}