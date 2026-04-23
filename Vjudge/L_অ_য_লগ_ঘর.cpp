// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  11.09.2025

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
void ok(string s, int pos, set<string> &st)
{
    if (pos + 2 <= s.size() - 5)
    {
        string t = s.substr(pos, 2);
        reverse(all(t));
        st.insert(t);
        ok(s, pos + 2, st);
    }
    if (pos + 3 <= s.size() - 5)
    {
        string t = s.substr(pos, 3);
        reverse(all(t));
        st.insert(t);
        ok(s, pos + 3, st);
    }
}
void solve(void)
{
    string s;
    cin >> s;
    if (s.size() < 5)
    {
        cout << 0 << '\n';
        return;
    }
    reverse(all(s));
    set<string> st;
    ok(s, 0, st);
    cout << st.size() << '\n';
    for (auto it : st)
        cout << it << '\n';
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