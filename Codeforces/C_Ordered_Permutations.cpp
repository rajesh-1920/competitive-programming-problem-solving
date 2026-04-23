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
    int n, k;
    cin >> n >> k;
    if (n < 62)
    {
        if (k > 1LL << (n - 1))
        {
            cout << -1 << '\n';
            return;
        }
        vector<int> v(n);
        int val = 1, pos = 0, temp = 1LL << (n - 2);
        int l = 0, r = n - 1;
        while (val <= n)
        {
            if (k <= temp)
            {
                pos = l++;
            }
            else
            {
                k = k - temp;
                pos = r--;
            }
            v[pos] = val++;
            temp /= 2;
        }
        for (auto it : v)
            cout << it << ' ';
        cout << '\n';
    }
    else
    {
        vector<int> v(n);
        int val = 1, pos = 0;
        int l = 0, r = n - 1;
        for (int i = 0; i < (n - 60); i++)
            v[i] = val++,l++;
        int temp = 1LL << (58);
        while (val <= n)
        {
            if (k <= temp)
            {
                pos = l++;
            }
            else
            {
                k = k - temp;
                pos = r--;
            }
            v[pos] = val++;
            temp /= 2;
        }
        for (auto it : v)
            cout << it << ' ';
        cout << '\n';
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