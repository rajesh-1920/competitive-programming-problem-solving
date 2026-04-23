// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  27.08.2025

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
const int N = 1e6 + 10;
//------------------------------(solve)----------------------------------------------------
int aa(int x, int y, vector<int> &v)
{
    if (x > y)
        swap(x, y);
    int ans = v[y];
    if (x)
        ans -= v[x - 1];
    return ans;
}
void solve(void)
{
    int n;
    string s;
    cin >> n >> s;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        v[i] = s[i] - '0';
        if (i)
            v[i] += v[i - 1];
    }
    int ans = 0, i = 0, j = 0;
    while (true)
    {
        ans += aa(i, j, v);
        if (i == j && i + 1 < n)
        {
            int xi = aa(i + 1, j, v), xj = aa(i, j + 1, v);
            if (xi < xj)
                i++;
            else
                j++;
        }
        else if (i == j)
            break;
        else if (i > j)
            j++;
        else
            i++;
    }
    cout << ans << '\n';
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