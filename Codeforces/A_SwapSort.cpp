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
    set<pair<int, int>> st;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        st.insert({v[i], i});
    }
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++)
    {
        int val = (*st.begin()).fi;
        int pos = (*st.begin()).sc;
        if (pos != i)
        {
            st.erase(st.find({v[i], i}));
            st.insert({v[i], pos});
            v[pos] = v[i];
            ans.emplace_back(i, pos);
        }
        st.erase(st.begin());
    }
    cout << ans.size() << '\n';
    for (auto it : ans)
        cout << it.fi << ' ' << it.sc << '\n';
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