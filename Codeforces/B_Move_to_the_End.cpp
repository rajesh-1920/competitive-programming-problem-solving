// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  28.04.2025

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
    vector<int> v(n), t;
    multiset<int> st;
    for (auto &it : v)
    {
        cin >> it;
        st.insert(it);
    }
    int s = 0;
    for (int i = n - 1; i > 0; i--)
    {
        s += v[i];
        st.erase(st.find(v[i]));
        int tt = *(--st.end());
        int an = s;
        if (v[i] < tt)
        {
            an -= v[i];
            an += tt;
        }
        t.push_back(an);
    }
    s += v[0];
    t.push_back(s);
    for (auto it : t)
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