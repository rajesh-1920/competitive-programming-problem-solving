// Author:  Rajesh Biswas
// CF    :  rajesh_1920
// Date  :  29.04.2026

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
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &it : v)
        cin >> it;
    int i = 0, j = n - 1;
    while (i < j)
    {
        if (v[i] == v[j])
            i++, j--;
        else
        {
            if (v[i] == k)
                i++;
            else if (v[j] == k)
                j--;
            else
            {
                cout << "No\n";
                return;
            }
        }
    }

    cout << "Yes\n";
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
        // cout << "Case #" << T << ": ";
        solve();
    }
    return 0;
}