// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  01.05.2025

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
    vector<int> v(2 * n), ans(2 * n + 1);
    set<int> st;
    for (auto &it : v)
    {
        cin >> it;
        st.insert(it);
    }
    sort(all(v));
    ans[0] = v.back();
    v.pop_back();
    reverse(all(v));
    for (int i = 0, t = 2; i < n; i++, t += 2)
    {
        ans[t] = v[i];
        if (i + n < v.size())
            ans[t + 1] = v[i + n];
    }
    int s = 0;
    for (int i = 2; i < 2 * n + 1; i++)
        if (i & 1)
            s += ans[i];
        else
            s -= ans[i];
    ans[1] = ans[0] - s;
    for (auto it : ans)
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