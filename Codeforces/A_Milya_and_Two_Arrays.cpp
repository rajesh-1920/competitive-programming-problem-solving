// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  07.02.2025

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
    vector<int> a(n);
    for (auto &it : a)
        cin >> it;
    vector<int> b(n);
    for (auto &it : b)
        cin >> it;
    sort(all(a));
    sort(all(b));
    for (int i = 1; i + 1 < n; i++)
    {
        set<int> st;
        st.insert(a[0] + b[0]);
        st.insert(a[n - 1] + b[n - 1]);
        for (int j = 0; j + 1 < n; j++)
        {
            st.insert(a[i] + b[j]);
            if (st.size() == 3)
            {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
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