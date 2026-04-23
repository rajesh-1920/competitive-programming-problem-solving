// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  04.02.2025

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
vector<int> prime;
vector<bool> is(N);
void sieve()
{
    prime.push_back(2);
    for (int i = 3; i < N; i += 2)
    {
        if (is[i] == 0)
        {
            prime.push_back(i);
            for (int j = i * i; j < N; j += 2 * i)
                is[j] = 1;
        }
    }
}
void solve(void)
{
    int n;
    cin >> n;
    if (n & 1)
    {
        if (n == 1)
            cout << "FastestFinger\n";
        else
            cout << "Ashishgup\n";
        return;
    }
    int x = n, od = 0, ev = 0;
    for (auto it : prime)
    {

        while (x % it == 0)
        {
            x /= it;
            if (it & 1)
                od++;
            else
                ev++;
        }
    }
    if (x > 1)
        od++;
    if (ev == 1)
    {
        if (od == 1)
            cout << "FastestFinger\n";
        else
            cout << "Ashishgup\n";
    }
    else
    {
        if (od == 0)
            cout << "FastestFinger\n";
        else
            cout << "Ashishgup\n";
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
    sieve();
    for (T = 1; T <= test; T++)
    {
        // cout << "Case " << T << ": ";
        solve();
    }
    return 0;
}