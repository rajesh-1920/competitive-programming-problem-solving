// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  27.01.2025

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
    ll s1, s2, t1, t2;
    char ch;
    cin >> s1 >> ch >> s2 >> t1 >> ch >> t2;
    ll total = t1 * 60 + t2;
    s1 += 24;
    s1 -= (total / 60);
    total %= 60;
    if (total > s2)
    {
        s1 -= 1;
        s2 += 60;
    }
    s2 -= total;
    if (s1 >= 24)
        s1 -= 24;
    if (s1 > 9)
        cout << s1;
    else
        cout << 0 << s1;
    cout << ch;
    if (s2 > 9)
        cout << s2;
    else
        cout << 0 << s2;
}
//-----------------------------------------------------------------------------------------
int main()
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