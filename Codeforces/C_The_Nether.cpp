// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  21.08.2025

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
    priority_queue<pair<int, int>> st;
    int mx = 0;
    for (int i = 1; i <=n; i++)
    {
        cout << "? " << i << ' ' << n << ' ';
        for (int j = 1; j <= n; j++)
            cout << j << ' ';
        cout << '\n';
        int x;
        cin >> x;
        st.push({x, i});
        mx = max(mx, x);
    }
    vector<int> v;
    v.push_back(st.top().sc);
    st.pop();
    while (st.size())
    {
        int t = st.top().fi;
        int nd = st.top().sc;
        st.pop();
        if (t == mx)
            continue;
        cout << "? " << v.back() << ' ' << 2 << ' ' << v.back() << ' ' << nd << '\n';
        int x;
        cin >> x;
        if (x == 2)
        {
            v.push_back(nd);
            mx = t;
        }
    }

    cout << "! ";
    cout << v.size() << ' ';
    for (auto it : v)
        cout << it << ' ';
    cout << '\n';
}
//-----------------------------------------------------------------------------------------
signed main()
{
    // cout << fixed << showpoint << setprecision(10);
    int test = 1, T;
    cin >> test;
    for (T = 1; T <= test; T++)
    {
        // cout << "Case " << T << ": ";
        solve();
    }
    return 0;
}