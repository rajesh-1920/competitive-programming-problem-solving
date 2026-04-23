// Author:  Rajesh Biswas
// CF    :  rajesh_1920
// Date  :  04.01.2026

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
const int inf = 1e16 + 7;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;
//------------------------------(solve)----------------------------------------------------
void solve(void)
{
    int n;
    cin >> n;
    vector<int> v(n + 1);
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({n, {-1, -n}});
    int i = 1;
    while (!pq.empty())
    {
        int sz = pq.top().fi, st = -pq.top().sc.fi, en = -pq.top().sc.sc;
        pq.pop();
        int mid = st + (en - st) / 2;
        v[mid] = i++;
        if (mid < en)
            pq.push({(en - mid), {-(mid + 1), -en}});
        if (st < mid)
            pq.push({(mid - st), {-st, -(mid - 1)}});
    }
    for (int i = 1; i <= n; i++)
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