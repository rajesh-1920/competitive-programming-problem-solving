// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  17.02.2026

#include <bits/stdc++.h>
using namespace std;
//----------------------------(definition section)-----------------------------------------
#define dbg(x) cout << #x << " = " << x << '\n'
#define fi first
#define sc second
#define int long long int

#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()

const double eps = 1e-1;
const int inf = 1e16 + 7;
const int MOD = 1e9 + 7;
const int N = 1e7 + 1;
//-----------------------------------------------------------------------------------------
int ok(int n, int fl, int last, vector<int> &seq, vector<int> &cold, vector<int> &hot)
{
    if (n >= seq.size())
        return 0;
    int ans = inf;
    if (fl)
    {
        if (last == seq[n])
        {
            ans = min(ans, ok(n + 1, 1, seq[n], seq, cold, hot) + hot[seq[n] - 1]);
            ans = min(ans, ok(n + 1, 0, last, seq, cold, hot) + hot[seq[n] - 1]);
        }
        else
        {
            ans = min(ans, ok(n + 1, 1, seq[n], seq, cold, hot) + cold[seq[n] - 1]);
            ans = min(ans, ok(n + 1, 0, last, seq, cold, hot) + cold[seq[n] - 1]);
        }
    }
    else
    {
        if (last == seq[n])
        {
            ans = min(ans, ok(n + 1, 0, seq[n], seq, cold, hot) + hot[seq[n] - 1]);
            ans = min(ans, ok(n + 1, 1, last, seq, cold, hot) + hot[seq[n] - 1]);
        }
        else
        {
            ans = min(ans, ok(n + 1, 0, seq[n], seq, cold, hot) + cold[seq[n] - 1]);
            ans = min(ans, ok(n + 1, 1, last, seq, cold, hot) + cold[seq[n] - 1]);
        }
    }
    return ans;
}
void solve(void)
{
    int n, k;
    cin >> n >> k;
    vector<int> seq(n), cold(k), hot(k);
    for (auto &it : seq)
        cin >> it;
    for (auto &it : cold)
        cin >> it;
    for (auto &it : hot)
        cin >> it;
    cout << ok(1, 0, seq.front(), seq, cold, hot) + cold[seq.front() - 1] << '\n';
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