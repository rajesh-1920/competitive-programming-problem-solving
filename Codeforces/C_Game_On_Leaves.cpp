// Author:  Rajesh Biswas
// CF    :  rajesh_1920
// Date  :  03.01.2026

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
void solve(void)
{
    int n, s;
    cin >> n >> s;
    vector<int> v(n + 1, 0);
    for (int x, y, i = 1; i < n; i++)
    {
        cin >> x >> y;
        v[x]++, v[y]++;
    }
    if (v[s] <= 1)
        cout << "Ayush\n";
    else if (n & 1)
        cout << "Ashish\n";
    else
        cout << "Ayush\n";
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