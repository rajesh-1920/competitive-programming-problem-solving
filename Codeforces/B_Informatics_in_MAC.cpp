// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  08.03.2025

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
    set<int> st, temp, tt;
    vector<int> v(n);
    for (int i = 0; i <= n + 1; i++)
    {
        st.insert(i);
        temp.insert(i);
        tt.insert(i);
    }
    for (auto &it : v)
    {
        cin >> it;
        st.insert(it);
        st.erase(it);
    }
    int mex = *st.begin(), t = 1, fl = 1;
    for (int i = 0; i < n; i++)
    {
        temp.insert(v[i]);
        temp.erase(v[i]);
        int mx = *temp.begin();
        if (mx == mex)
        {
            fl = 0;
            t = i + 1;
            break;
        }
    }
    if (fl)
        cout << -1 << '\n';
    else
    {

        for (int i = t; i < n; i++)
        {
            tt.insert(v[i]);
            tt.erase(v[i]);
        }
        int mx = *tt.begin();
        if (mx == mex)
        {
            cout << 2 << '\n';
            cout << 1 << ' ' << t << '\n'
                 << t + 1 << ' ' << n << '\n';
        }
        else
            cout << -1 << '\n';
    }
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