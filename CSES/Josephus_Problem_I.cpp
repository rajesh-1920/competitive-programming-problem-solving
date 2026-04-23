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
    int n;
    cin >> n;
    set<int> st;
    for (int i = 1; i <= n; i++)
        st.insert(i);
    int cnt = 2, p = 2;
    while (true)
    {
        if (st.find(p) != st.end())
            cout << p << ' ', st.erase(p);
        if (st.empty())
            break;
        if (st.lower_bound(p + cnt) == st.end())
        {
            if (st.upper_bound(p) == st.end())
            {
                int t = *st.begin();
                st.erase(t);
                if (!st.empty())
                    p = *st.begin();
                else
                    p = t;
                st.insert(t);
            }
            else
                p = *st.begin();
            cnt <<= 1;
        }
        else
            p += cnt;
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