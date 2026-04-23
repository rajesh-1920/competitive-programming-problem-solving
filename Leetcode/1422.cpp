// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  10.12.2024

#include <bits/stdc++.h>
using namespace std;
//-----------------------------------------------------------------------------------------
class Solution
{
    typedef long long int ll;
#define dbg(x) cout << #x << " = " << x << '\n'
#define fi first
#define sc second

#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()

    const double eps = 1e-1;
    const ll inf = 9e15 + 7;
    const ll MOD = 1e9 + 7;
    const ll N = 1e9 + 10;

public:
    int maxScore(string s)
    {
        if (s[s.size() - 1] == '0')
            s.pop_back();
        reverse(all(s));
        if (s[s.size() - 1] == '1')
            s.pop_back();
        reverse(all(s));
        ll ans = 0;
        vector<ll> zero(s.size() + 5, 0), one(s.size() + 5, 0);
        for (ll i = 0; i < s.size(); i++)
        {
            zero[i + 1] = zero[i];
            if (s[i] == '0')
                zero[i + 1]++;
        }
        for (ll i = s.size() - 1; i >= 0; i--)
        {
            one[i + 1] = one[i + 2];
            if (s[i] == '1')
                one[i + 1]++;
        }
        for (ll i = 1; i <= s.size(); i++)
            ans = max(ans, zero[i] + one[i]);
        // dbg(ans);
        return ans;
    }
};
//-----------------------------------------------------------------------------------------
void solve(void)
{
    string s;
    cin >> s;
    Solution mx;
    cout << mx.maxScore(s);
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