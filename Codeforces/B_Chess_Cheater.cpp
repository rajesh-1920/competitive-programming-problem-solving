// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  23.04.2025

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
    int n, k, cl = 0;
    string s;
    cin >> n >> k >> s;
    while (s.size())
    {
        if (s.back() == 'W')
            break;
        s.pop_back();
        cl++;
    }
    if (s.empty())
    {
        k = min(k, n);
        int ans = k * 2;
        if (k)
            ans--;
        cout << ans << '\n';
        return;
    }
    reverse(all(s));
    while (s.size())
    {
        if (s.back() == 'W')
            break;
        s.pop_back();
        cl++;
    }
    reverse(all(s));
    int ans = 0, cnt = 0, pre = 0;
    multiset<int> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'W')
        {
            if (cnt)
                st.insert(cnt);
            cnt = 0, ans++;
            if (pre)
                ans++;
            pre = 1;
        }
        else
            cnt++, pre = 0;
    }
    while (k)
    {
        if (st.empty())
            break;
        int t = *st.begin();
        st.erase(st.begin());
        if (k >= t)
        {
            k -= t;
            ans += t * 2 + 1;
        }
        else
        {
            ans += k * 2;
            k = 0;
        }
    }
    k = min(cl, k);
    ans += k * 2;
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