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
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> v(n);
    for (auto &it : v)
        cin >> it;
    sort(all(v));
    multiset<int> st;
    int pre = v.front();
    for (int i = 1; i < n; i++)
    {
        if (v[i] - pre > x)
        {
            int t = (v[i] - pre) / x;
            if ((v[i] - pre) % x == 0)
                t--;
            st.insert(t);
        }
        pre = v[i];
    }
    while (st.size())
    {
        int t = *st.begin();
        if (t <= k)
        {
            k -= t;
            st.erase(st.begin());
        }
        else
            break;
    }
    cout << st.size() + 1 << '\n';
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