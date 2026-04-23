// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  28.04.2025

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
const int N = 7e6 + 10;
//-----------------------------------------------------------------------------------------
vector<int> prime;
bool is[N];
void sieve()
{
    prime.push_back(2);
    for (int i = 3; i < N; i += 2)
    {
        if (is[i] == false)
        {
            prime.push_back(i);
            for (int j = i; j < N; j += i * 2)
                is[j] = true;
        }
    }
}
void solve(void)
{
    int n, t = 0;
    cin >> n;
    vector<int> v(n);
    for (auto &it : v)
        cin >> it;
    sort(rall(v));
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (prime[i] <= v[i])
            t += v[i] - prime[i];
        else
        {
            int need = prime[i] - v[i];
            if (need <= t)
                t -= need;
            else
                break;
        }
        cnt++;
    }
    cout << n - cnt << '\n';
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