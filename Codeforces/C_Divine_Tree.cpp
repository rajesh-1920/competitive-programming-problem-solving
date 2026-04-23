// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  06.07.2025

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
//-----------------------------------------------------------------------------------------
void solve(void)
{
    int n, m;
    cin >> n >> m;
    if (m < n || m > (n * (n + 1)) / 2)
    {
        cout << -1 << '\n';
        return;
    }
    set<int> st;
    for (int i = 1; i <= n; i++)
        st.insert(i);
    vector<int> ans;
    while (st.size())
    {
        int t = st.size();
        t--;
        if (st.find((m - t)) != st.end())
        {
            st.erase(m - t);
            ans.push_back(m - t);
            break;
        }
        t = *(--st.end());
        st.erase(t);
        ans.push_back(t);
        m -= t;
    }
    for (auto it : st)
        ans.push_back(it);
    cout << ans[0] << '\n';
    for (int i = 1; i < ans.size(); i++)
        cout << ans[i - 1] << ' ' << ans[i] << '\n';
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