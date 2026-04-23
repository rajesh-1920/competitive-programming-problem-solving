// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  01.02.2025

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
    set<int> st;
    for (int i = 1; i <= n; i++)
        st.insert(i);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int x;
            cin >> x;
            if (x == 1)
            {
                st.insert(i);
                st.erase(i);
            }
            if (x == 2)
            {
                st.insert(j);
                st.erase(j);
            }
            if (x == 3)
            {
                st.insert(j);
                st.erase(j);
                st.insert(i);
                st.erase(i);
            }
        }
    }
    cout << st.size() << '\n';
    for (auto it : st)
        cout << it << ' ';
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