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
    int n;
    cin >> n;
    vector<pair<int, int>> vp(n);
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vp[i].fi;
        vp[i].sc = i;
    }
    sort(all(vp));
    int x = 100000000;
    ans[vp[0].sc] = x;
    int hate = vp[0].fi * x - x;
    for (int i = 1; i < n; i++)
    {
        int need = (vp[0].fi * x + 1) / vp[i].fi;
        if ((vp[0].fi * x+1) % vp[i].fi)
            need++;
        if (need <= hate)
        {
            hate -= need;
            ans[vp[i].sc] = need;
        }
        else
        {
            cout << -1 << '\n';
            return;
        }
    }
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