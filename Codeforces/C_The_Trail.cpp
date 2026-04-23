// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  13.01.2025

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
//----------------------------(definition section)-----------------------------------------
#define dbg(x) cout << #x << " = " << x << '\n'
#define fi first
#define sc second

#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()

const double eps = 1e-1;
const ll inf = 9e15 + 7;
const ll MOD = 1e9 + 7;
const ll N = 1e5 + 10;
//-----------------------------------------------------------------------------------------
void solve(void)
{
    ll n, m;
    string s;
    cin >> n >> m >> s;
    ll a[n][m], row[n], col[m];
    for (ll i = 0; i < n; i++)
    {
        row[i] = 0;
        for (ll j = 0; j < m; j++)
        {
            cin >> a[i][j];
            row[i] += a[i][j];
        }
    }
    for (ll i = 0; i < m; i++)
    {
        col[i] = 0;
        for (ll j = 0; j < n; j++)
            col[i] += a[j][i];
    }
    ll i = 0, j = 0;
    for (ll p = 0; p < s.size(); p++)
    {
        if (s[p] == 'D')
        {
            a[i][j] = -row[i];
            col[j] -= row[i];
            row[i] = 0;
            i++;
        }
        else
        {
            a[i][j] = -col[j];
            row[i] -= col[j];
            col[j] = 0;
            j++;
        }
    }
    a[n - 1][m - 1] = -col[m - 1];
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
            cout << a[i][j] << ' ';
        cout << '\n';
    }
}
//-----------------------------------------------------------------------------------------
int main()
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