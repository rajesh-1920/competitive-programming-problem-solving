// Author:  Rajesh Biswas
// Date  :  15.12.2024

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
const ll N = 1e9 + 10;
//-----------------------------------------------------------------------------------------
void solve(void)
{
    ll k, l1, r1, l2, r2;
    cin >> k >> l1 >> r1 >> l2 >> r2;
    ll cnt = (r1 - l1 + 1) * (r2 - l2 + 1);
    ll x = 1;
    while (cnt)
    {
        x++;
        cnt /= k;
    }
    if (l2 >= l1)
    {
        if (r1 <= r2)
            x += (r1 - l1 + 1);
        else
            x += (r2 - l1 + 1);
    }
    else
    {
        if (r1 <= r2)
            x += (r1 - l2 + 1);
        else
            x += (r2 - l2 + 1);
    }
    cout << x << '\n';
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