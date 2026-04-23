// Author:  Rajesh Biswas
// CF    :  rajesh_1920
// Date  :  15.01.2026

#include <bits/stdc++.h>
using namespace std;
//----------------------------(definition section)-----------------------------------------
#define dbg(x) cout << #x << " = " << x << '\n';
#define int long int
#define fi first
#define sc second

#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()

const double eps = 1e-1;
const int inf = 9e16 + 7;
const int MOD = 1e8;
const int N = 1e5 + 10;
//------------------------------(solve)----------------------------------------------------
void solve(void)
{
    int n;
    cin >> n;
    vector<int> a(n), b(n), s(n, 0);
    for (auto &it : a)
        cin >> it;
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        s[i] = a[i] * b[i];
        if (i)
            s[i] += s[i - 1];
    }
    int mx = 0;
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
        {
            int sum = s[n - 1] - s[j];
            if (i)
                sum += s[i - 1];
            int k = i, l = j;
            while (k <= j)
            {
                sum += (a[l] * b[k]);
                k++, l--;
            }
            mx = max(mx, sum);
        }
    cout << mx << '\n';
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