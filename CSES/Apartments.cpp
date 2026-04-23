// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  31.10.2025

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
    int n, m, k;
    cin >> n >> m >> k;
    multiset<int> st, temp;
    while (n--)
    {
        int x;
        cin >> x;
        st.insert(x);
    }
    while (m--)
    {
        int x;
        cin >> x;
        temp.insert(x);
    }
    int ans = 0;
    for (auto x : temp)
    {
        x -= k;
        if (st.lower_bound(x) != st.end())
        {
            int t = *(st.lower_bound(x));
            if (t <= x + k + k)
            {
                ans++;
                st.erase(st.lower_bound(x));
            }
        }
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