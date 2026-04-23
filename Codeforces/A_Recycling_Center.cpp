// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  27.07.2025

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
    int n, c;
    cin >> n >> c;
    multiset<int> st;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        st.insert(x);
    }
    int ans = 0;
    while (st.size())
    {
        if ((*st.begin()) > c)
        {
            ans += st.size();
            break;
        }
        multiset<pair<int, int>> ms;
        for (auto it : st)
        {
            if (it > c)
                break;
            int t = it;
            int cnt = 0;
            while (t <= c)
            {
                cnt++;
                t *= 2;
            }
            ms.insert({cnt, it});
        }
        st.erase(st.find((*(ms.begin())).sc));
        multiset<int> ss;
        for (auto it : st)
            ss.insert(it * 2);
        st.clear();
        for (auto it : ss)
            st.insert(it);
        // for (auto it : st)
        //     cout << it << ' ';
        // cout << '\n';
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