// Author:  Rajesh Biswas
// CF    :  rajesh_1920
// Date  :  08.01.2026

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
    int n;
    cin >> n;
    vector<int> vrr(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++)
        cin >> vrr[i];
    for (int i = 0; i < n; i++)
        vrr[i] -= (i + 1);
    sort(all(vrr));
    int sum = 0, cnt = 0;
    for (int i = 0; i < n - 1; i++)
        if (vrr[i] == vrr[i + 1])
            cnt++;
        else
        {
            sum += ((cnt * (cnt + 1) / 2));
            cnt = 0;
        }
    sum += ((cnt * (cnt + 1) / 2));
    cout << sum << "\n";
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