// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  01.06.2025

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
    int n, g, fl = 1;
    cin >> n;
    vector<int> v(n);
    for (auto &it : v)
    {
        cin >> it;
        if (fl)
            g = it, fl = 0;
        else
            g = __gcd(g, it);
    }

    int cnt = 0;
    for (auto it : v)
        if (it == g)
            cnt++;
    int ans = n - cnt;
    // dbg(g);
    if (cnt == 0)
    {
        // dbg(g);
        set<int> st;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                st.insert(__gcd(v[i], v[j]));

        if (st.find(g) != st.end())
            ans = n;
        else
        {
            set<int> temp;
            for (int i = 0; i < n; i++)
                for (auto it : st)
                    temp.insert(__gcd(v[i], it));
            if (temp.find(g) != temp.end())
                ans = n + 1;
            else
            {
                set<int> tm;
                for (int i = 0; i < n; i++)
                    for (auto it : temp)
                        tm.insert(__gcd(v[i], it));
                if (tm.find(g) != tm.end())
                    ans = n + 2;
                else
                    ans = n + 3;
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
    cin >> test;
    for (T = 1; T <= test; T++)
    {
        // cout << "Case " << T << ": ";
        solve();
    }
    return 0;
}