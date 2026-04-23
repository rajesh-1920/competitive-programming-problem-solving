// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  13.11.2025

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
void solve(void)
{
    int n, m;
    cin >> n >> m;
    multiset<int> st;
    st.insert(n);
    set<int> pos;
    pos.insert(0), pos.insert(n);
    while (m--)
    {
        int x;
        cin >> x;
        int t1 = 0;
        if (x != 0)
            t1 = *(--pos.lower_bound(x));
        int t2 = *pos.lower_bound(x);
        st.erase(st.find(t2 - t1));
        pos.insert(x);
        st.insert(t2 - x);
        st.insert(x - t1);
        cout << *(--st.end()) << ' ';
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