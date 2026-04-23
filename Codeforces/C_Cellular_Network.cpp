// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  16.02.2026

#include <bits/stdc++.h>
using namespace std;
//----------------------------(definition section)-----------------------------------------
#define dbg(x) cout << #x << " = " << x << '\n'
#define fi first
#define sc second
#define int long long int

#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()

const double eps = 1e-1;
const int MOD = 1e9 + 7;
const int N = 1e7 + 1;
//-----------------------------------------------------------------------------------------
void solve(void)
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (auto &it : v)
        cin >> it;
    set<int> st;
    while (m--)
    {
        cin >> n;
        st.insert(n);
    }
    vector<int> temp;
    for (auto &it : st)
        temp.emplace_back(it);
    int ans = 0;
    for (auto &it : v)
    {
        int i = lower_bound(all(temp), it) - temp.begin();
        if (i > 0 && i < temp.size())
            ans = max(ans, (min((temp[i] - it), (it - temp[i - 1]))));
        else if (i < temp.size())
            ans = max(ans, temp[i] - it);
        else if (i)
            ans = max(ans, it - temp[i - 1]);
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