// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  06.06.2025

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
    int n;
    cin >> n;
    vector<int> v(n), cnt(n + 5, 0), next(n + 5, n), temp(n + 5, -1);
    for (auto &it : v)
    {
        cin >> it;
        cnt[it]++;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (temp[v[i]] != -1)
            next[i] = temp[v[i]];
        temp[v[i]] = i;
    }
    set<int> pos;
    pos.insert(0);
    int ans = 1, i = 0, t = next[0], fl = 0;
    while (true)
    {
        set<int> st;
        for (; i < t; i++)
        {
            if (next[i] == n)
            {
                fl = 1;
                break;
            }
            st.insert(v[i]);
            pos.insert(next[i]);
        }
        t = next[*pos.rbegin()];
        // dbg(st.size());
        if (fl)
        {
            for (; i < n; i++)
            {
                if (st.find(v[i]) != st.end())
                    st.erase(st.find(v[i]));
            }
            if (st.empty())
                ans++;
            break;
        }
        ans++;
    }
    ans = min(ans, cnt[v[0]]);
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