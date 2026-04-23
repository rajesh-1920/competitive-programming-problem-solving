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
    map<int, int> mp;
    set<int> st;
    int mx = 0;
    while (n--)
    {
        int it;
        cin >> it;
        mp[it]++;
        st.insert(it);
        mx = max(mx, it);
    }
    set<int> ans;
    ans.insert(1);
    for (auto it : st)
    {
        mp[it]--;
        for (int j = it; j <= mx; j += it)
        {
            if (mp[j] > 0)
            {
                ans.insert(it);
                break;
            }
        }
        mp[it]++;
    }
    cout << *(--ans.end());
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