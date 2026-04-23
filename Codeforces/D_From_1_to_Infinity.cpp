// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  21.08.2025

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
//------------------------------(solve)----------------------------------------------------

int sum_of_all_digits(int n)
{
    int res = 0, p = 1;
    while (p <= n)
    {
        res += (n / (10 * p)) * 45 * p;
        int hate = n % (10 * p);
        int carry = hate / p;
        res += p * (carry * (carry - 1) / 2);
        res += carry * (hate % p + 1);
        p *= 10;
    }
    return res;
}

int sum_range(int a, int b)
{
    if (a > b)
        return 0;
    return sum_of_all_digits(b) - sum_of_all_digits(a - 1);
}
void solve(void)
{
    int n;
    cin >> n;
    int ans = 0, d = 1;
    while (n)
    {
        int left = pow(10, d - 1);
        int total = (9 * left) * d;
        if (n >= total)
        {
            ans += sum_range(left, left * 10 - 1);
            n -= total;
        }
        else
        {
            int m = n / d;
            ans += sum_range(left, left + m - 1);
            n = n % d;
            int tmp = left + m;
            string s = to_string(tmp);
            for (int i = 0; i < n; i++)
                ans += s[i] - '0';
            break;
        }
        d++;
    }
    cout << ans << '\n';
}
//-----------------------------------------------------------------------------------------
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1, T;
    cin >> test;
    for (T = 1; T <= test; T++)
    {
        solve();
    }
    return 0;
}
