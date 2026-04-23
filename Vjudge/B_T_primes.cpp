// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  24.01.2025

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
const ll N = 1e6 + 10;
//-----------------------------------------------------------------------------------------
bool prime[N];
void sieve()
{
    for (ll i = 2; i < N; i++)
    {
        if (prime[i] == 0)
        {
            for (ll j = i + i; j < N; j += i)
                prime[j] = 1;
        }
    }
}
void solve(void)
{
    ll n;
    cin >> n;
    while (n--)
    {
        ll it;
        cin >> it;
        ll x = sqrt(it), fl = 0;
        for (ll i = x - 10; i <= x + 10; i++)
        {
            if (i * i == it && it > 1 && i > 0)
            {
                if (prime[i] == 0)
                    cout << "YES\n";
                else
                    cout << "NO\n";
                fl = 1;
                break;
            }
        }
        if (fl == 0)
            cout << "NO\n";
    }
}
//-----------------------------------------------------------------------------------------
int main()
{
    // cout << fixed << showpoint << setprecision(10);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1, T;
    sieve();
    // cin >> test;
    for (T = 1; T <= test; T++)
    {
        // cout << "Case " << T << ": ";
        solve();
    }
    return 0;
}