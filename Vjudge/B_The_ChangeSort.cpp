// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  27.08.2025

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
    vector<int> v(n);
    set<pair<int, int>> st;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        st.insert({v[i], i});
    }
    int i = 0;
    vector<pair<int, int>> vp;
    while (i < n)
    {
        int pos = (*st.begin()).sc;
        int val = (*st.begin()).fi;
        st.erase(st.begin());
        if (v[i] == val)
            i++;
        else
        {
            vp.push_back({i, pos});
            st.erase({v[i], i});
            st.insert({v[i], pos});
            swap(v[i], v[pos]);
            i++;
        }
    }
    // for (auto it : v)
    //     cout << it << ' ';
    // cout << '\n';
    cout << vp.size() << '\n';
    for (auto it : vp)
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