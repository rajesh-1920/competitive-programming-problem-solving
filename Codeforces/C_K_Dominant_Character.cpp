// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  28.08.2025

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
    string s;
    cin >> s;
    int ans = inf, l = 1, r = s.size();
    while (l <= r)
    {
        int m = (l + r) / 2;
        multiset<char> st;
        set<char> ss;
        for (int i = 0; i < m; i++)
            st.insert(s[i]), ss.insert(s[i]);
        int fl = 1;
        for (int i = m; i < s.size(); i++)
        {
            st.erase(st.find(s[i - m]));
            st.insert(s[i]);
            stack<char> stc;
            for (auto it : ss)
                if (st.find(it) == st.end())
                    stc.push(it);
            while (!stc.empty())
            {
                ss.erase(stc.top());
                stc.pop();
            }
            if (ss.size() == 0)
                fl = 0;
            if (fl == 0)
                break;
        }
        if (fl)
            ans = min(ans, m), r = m - 1;
        else
            l = m + 1;
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