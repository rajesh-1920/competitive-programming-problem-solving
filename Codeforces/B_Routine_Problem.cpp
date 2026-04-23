// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  22.01.2025

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
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll lc = (c * d) / (__gcd(c, d));
    ll nom1, denom1, nom2, denom2;
    a *= lc, b *= lc;

    ll t = b / d;
    ll tc = t * c;
    nom1 = a - tc;
    denom1 = a;

    t = a / c;
    tc = t * d;
    nom2 = b - tc;
    denom2 = b;
    float n1 = nom1;
    float n2 = nom2;
    float dn1 = denom1;
    float dn2 = denom2;

    if ((n1 / dn1) > (n2 / dn2) && n2 >= 0)
    {
        swap(nom1, nom2);
        swap(denom1, denom2);
    }
    if (n1 < 0)
    {
        swap(nom1, nom2);
        swap(denom1, denom2);
    }
    ll g = __gcd(nom1, denom1);
    cout << nom1 / g << '/' << denom1 / g;
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