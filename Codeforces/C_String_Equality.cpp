// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  25.03.2025

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
    int n, k;
    string a, b;
    cin >> n >> k >> a >> b;
    vector<int> v(n + 1, 0), can(n + 1, 0);
    a = '*' + a;
    b = '*' + b;
    for (int i = n-k+1; i >= 1; i--)
    {
        if (a[i] == a[n-k+1])
            can[i] = 1;
        else
            break;
    }
    for (int i = 1; i <= n; i++)
    {
        if (can[i])
        {
            v[i] = v[i - 1];
            if (a[i] + v[i] >= 'z')
                a[i] = 'z';
            else
                a[i] = char(a[i] + v[i]);
            if (a[i] < b[i])
            {
                v[i] += b[i] - a[i];
                a[i] = b[i];
            }
        }
        if (a[i] == b[i])
            continue;
        else
        {
            cout << a << '\n';
            cout << "NO\n";
            return;
        }
    }
    cout << a << ' ';
    cout << "YES\n";
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