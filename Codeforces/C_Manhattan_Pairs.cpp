// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  19.07.2025

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
bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
{
    if (a.sc.fi < b.sc.fi)
        return true;
    if (a.sc.fi > b.sc.fi)
        return false;
    return a.fi < b.fi;
}
void solve(void)
{
    int n;
    cin >> n;
    vector<pair<int, pair<int, int>>> v(n);
    int cnt = 1;
    for (auto &it : v)
    {
        cin >> it.fi >> it.sc.fi;
        it.sc.sc = cnt++;
    }
    sort(all(v));
    int ans = 0;
    for (int i = 0; i < n / 2; i++)
        ans += abs(v[i].fi - v[i + n / 2].fi) + abs(v[i].sc.fi - v[i + n / 2].sc.fi);
    int temp = ans;
    ans = 0;
    sort(all(v), cmp);
    for (int i = 0; i < n / 2; i++)
        ans += abs(v[i].fi - v[i + n / 2].fi) + abs(v[i].sc.fi - v[i + n / 2].sc.fi);
    if (temp >= ans)
        sort(all(v));
    for (int i = 0; i < n / 2; i++)
        cout << v[i].sc.sc << ' ' << v[i + n / 2].sc.sc << '\n';
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