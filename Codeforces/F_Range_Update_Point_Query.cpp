// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  31.07.2025

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
    int n, q;
    cin >> n >> q;
    set<int> st;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        if (v[i] > 9)
            st.insert(i);
    }
    while (q--)
    {
        int x;
        cin >> x;
        if (x == 2)
        {
            int l;
            cin >> l;
            cout << v[l] << '\n';
        }
        else
        {
            int l, r;
            cin >> l >> r;
            auto it = st.lower_bound(l);
            while (it != st.end() && *it <= r)
            {
                int s = 0, a = v[*it];
                while (a)
                    s += a % 10, a /= 10;
                v[*it] = s;
                if (v[*it] < 10)
                    it = st.erase(it);
                else
                    it++;
            }
        }
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