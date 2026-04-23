// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  10.08.2025

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
    int n;
    cin >> n;
    if (n <= 3)
    {
        cout << "codeforce";
        while (n--)
            cout << 's';
        return;
    }
    int t = 1;
    multiset<int> st;
    while (st.size() < 10)
        st.insert(1);
    while (t < n)
    {
        int xx = *st.begin();
        st.erase(st.begin());
        st.insert(xx + 1);
        t = t / xx;
        t *= (xx + 1);
    }

    string s = "codeforces";
    t = 0;
    string ans = "";
    for (auto it : st)
    {
        int x = it;
        while (x--)
            ans.push_back(s[t]);
        t++;
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