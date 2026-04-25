// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  25.04.2026

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
const int N = 1e6 + 1;

//-----------------------------------------------------------------------------------------
void solve(void)
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &it : v)
        cin >> it;
    set<int> st;
    st.insert(0);
    int fl = 0, s = 0;
    for (auto &it : v)
    {
        if (fl)
            s += it;
        else
            s -= it;
        fl ^= 1;
        if (st.count(s))
        {
            cout << "YES\n";
            return;
        }
        st.insert(s);
    }
    cout << "NO\n";
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