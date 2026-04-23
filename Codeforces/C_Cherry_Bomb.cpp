// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  24.04.2025

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
    int n, k;
    cin >> n >> k;
    vector<int> b(n), a(n);
    for (auto &it : a)
        cin >> it;
    set<int> st;
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        if (b[i] != -1)
            st.insert(a[i] + b[i]);
    }
    if (st.size() > 1)
        cout << 0 << '\n';
    else if (st.size() == 1)
    {
        int t = *st.begin();
        for (int i = 0; i < n; i++)
        {
            if (b[i] == -1)
            {
                if (t - a[i] < 0 || t - a[i] > k)
                {
                    cout << 0 << '\n';
                    return;
                }
            }
        }
        cout << 1 << '\n';
    }
    else
    {
        sort(all(a));
        int x = a.back() - a[0];
        int ans = k - x + 1;
        ans = max(0LL, ans);
        cout << ans << '\n';
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