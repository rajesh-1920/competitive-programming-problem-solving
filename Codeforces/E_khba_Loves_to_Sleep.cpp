// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  27.10.2025

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
int ok(vector<int> &v, int pos)
{
    int mn = inf;
    for (auto it : v)
        mn = min(mn, abs(it - pos));
    return mn;
}
void solve(void)
{
    int n, x, k;
    cin >> n >> k >> x;
    vector<int> v(n);
    for (auto &it : v)
        cin >> it;
    set<int> st;
    while (v.size() < n + k)
    {
        int l = 0, r = x, ans = inf;
        while (l <= r)
        {
            int m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
            int t1 = ok(v, m1);
            int t2 = ok(v, m2);
            if (t1 == t2)
            {
                if (st.find(m1) == st.end())
                    ans = m1, l++, r--;
                elser
                    l++;
            }
            else if (t1 > t2)
                r = m2 - 1;
            else
                l = m1 + 1;
        }
        v.push_back(ans), st.insert(ans);
    }
    for (int i = n; i < v.size(); i++)
        cout << v[i] << ' ';
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