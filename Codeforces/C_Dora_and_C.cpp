// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  01.06.2025

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
bool ok(int &val, int &c, vector<int> &v)
{
}
void solve(void)
{
    int n, c, d;
    cin >> n >> c >> d;
    vector<int> v(n);
    for (auto &it : v)
        cin >> it;
    if (n == 1)
    {
        cout << 0 << '\n';
        return;
    }
    sort(all(v));
    c = __gcd(c, d);
    for (int i = 0; i < n; i++)
        v[i] = v[i] + c * ((v.back() - v[i]) / c);
    sort(all(v));
    int ans = v.back() - v[0];
    multiset<int> st;
    for (auto it : v)
        st.insert(it);
    for (int i = 0; i < n; i++)
    {
        st.erase(st.find(v[i]));
        st.insert(v[i] + c);
        ans = min(ans, ((*st.rbegin()) - (*st.begin())));
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
    cin >> test;
    for (T = 1; T <= test; T++)
    {
        // cout << "Case " << T << ": ";
        solve();
    }
    return 0;
}