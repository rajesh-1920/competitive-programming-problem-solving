// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  28.01.2025

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
const ll inf = 9e16 + 7;
const ll MOD = 1e9 + 7;
const ll N = 1e5 + 10;
//-----------------------------------------------------------------------------------------
void solve(void)
{
    ll n;
    cin >> n;
    string s = "O-|-OOOO";
    if (n == 0)
        cout << s << '\n';
    while (n)
    {
        ll t = n % 10;
        n /= 10;
        if (t == 0)
            s = "O-|-OOOO";
        if (t == 1)
            s = "O-|O-OOO";
        if (t == 2)
            s = "O-|OO-OO";
        if (t == 3)
            s = "O-|OOO-O";
        if (t == 4)
            s = "O-|OOOO-";
        if (t == 5)
            s = "-O|-OOOO";
        if (t == 6)
            s = "-O|O-OOO";
        if (t == 7)
            s = "-O|OO-OO";
        if (t == 8)
            s = "-O|OOO-O";
        if (t == 9)
            s = "-O|OOOO-";
        cout << s << '\n';
    }
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