// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  16.06.2025

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
int ok(int n, vector<int> a, vector<int> b)
{
    if (n == a.size())
        return inf;
    int fl = 1;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] > b[i])
            fl = 0;
        if (i)
            if (a[i - 1] > a[i] || b[i - 1] > b[i])
                fl = 0;
    }
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << ' ';
    cout << '\n';
    for (int i = 0; i < a.size(); i++)
        cout << b[i] << ' ';
    cout << '\n';
    cout << '\n';

    int ans = 0;
    if (fl)
        return 0;
    else
        ans = inf;
    ans = min(ans, ok(n + 1, a, b));
    swap(a[n], b[n]);
    ans = min(ans, ok(n + 1, a, b) + 1);
    swap(a[n], b[n]);
    if (n < a.size() - 1)
    {
        swap(a[n], a[n + 1]);
        ans = min(ans, ok(n + 1, a, b) + 1);
        swap(a[n], a[n + 1]);
        swap(b[n], b[n + 1]);
        ans = min(ans, ok(n + 1, a, b) + 1);
        swap(b[n], b[n + 1]);
    }
    return ans;
}
void solve(void)
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &it : a)
        cin >> it;
    for (auto &it : b)
        cin >> it;

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