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
    int n, k;
    cin >> n >> k;
    set<int> st;
    if (n == 1)
        st.insert(1);
    else if (k % 2 == 0)
    {
        st.insert(1);
        st.insert(k);
        st.insert(k + 1);
    }
    else
    {
        if (k != 1 && k != n)
        {
            st.insert(1);
            st.insert(k - 1);
            st.insert(k);
            st.insert(k + 1);
            st.insert(k + 2);
        }
        else
        {
            cout << -1 << '\n';
            return;
        }
    }
    cout << st.size() << '\n';
    for (auto it : st)
        cout << it << ' ';
    cout << '\n';
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