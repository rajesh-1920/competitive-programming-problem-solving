// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  27.04.2025

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
const int MOD = 7;
const int N = 1e5 + 10;
//-----------------------------------------------------------------------------------------
set<int> st;
void ok(int n, int c4, int c7)
{
    if (n >inf)
        return;
    if (c4 == c7 && n > 0)
        st.insert(n);
    ok(n * 10 + 4, c4 + 1, c7);
    ok(n * 10 + 7, c4, c7 + 1);
}
void solve(void)
{
    int n;
    cin >> n;
    ok(0, 0, 0);
    cout << *(st.lower_bound(n));
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