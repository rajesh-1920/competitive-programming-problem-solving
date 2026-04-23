// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  08.02.2025

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
    vector<int> v(n);
    map<int, int> mp;
    for (auto &it : v)
    {
        cin >> it;
        mp[it]++;
    }
    sort(all(v));
    int x = v[0] * v[n - 1], ans = x;
    set<int> st;
    for (int i = 0; n - i - 1 >= 0; i++)
        st.insert(v[i] * v[n - i - 1]);
    if (st.size() > 1)
        ans = -1;
    for (int i = 2; i * i <= x; i++)
    {
        if (ans == -1)
            break;
        if (x % i == 0)
        {
            if (mp[i] == 0 || mp[x / i] == 0)
                ans = -1;
        }
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