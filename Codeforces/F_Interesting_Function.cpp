// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  07.02.2025

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
int cnt(int l, int r)
{
    int cnt = 0;
    while (l < r)
    {
        int x = l, y = l + 1;
        l++;
        string s1 = to_string(x), s2 = to_string(y);
        reverse(all(s1));
        reverse(all(s2));
        while (s1.size() > s2.size())
            s2.push_back('0');
        while (s1.size() < s2.size())
            s1.push_back('0');
        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] != s2[i])
                cnt++;
        }
    }
    return cnt;
}
int powr(int a)
{
    int ans = 0;
    for (int i = 0; i < a; i++)
        ans = ans * 10 + 1;
    return ans;
}
void solve(void)
{
    int l, r;
    cin >> l >> r;
    string s1 = to_string(l), s2 = to_string(r);
    reverse(all(s1));
    reverse(all(s2));
    while (s1.size() > s2.size())
        s2.push_back('0');
    while (s1.size() < s2.size())
        s1.push_back('0');
    reverse(all(s1));
    reverse(all(s2));
    int ans = 0, n = s1.size();
    for (int i = 0; i < s1.size(); i++)
    {
        int t = powr(n - i);
        ans += t * (s2[i] - '0');
        ans -= t * (s1[i] - '0');
    }
    cout << ans << '\n';
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