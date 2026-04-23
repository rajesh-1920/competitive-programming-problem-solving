// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  01.04.2025

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
vector<int> ans;
void ok()
{
    vector<int> v, t;
    v.push_back(6);
    v.push_back(9);
    ans.push_back(6);
    ans.push_back(9);
    while (v.size())
    {
        t.push_back(v.back() * 10 + 6);
        ans.push_back(t.back());
        t.push_back(v.back() * 10 + 9);
        ans.push_back(t.back());
        v.pop_back();
    }
    while (t.size())
    {
        v.push_back(t.back() * 10 + 6);
        ans.push_back(v.back());
        v.push_back(t.back() * 10 + 9);
        ans.push_back(v.back());
        t.pop_back();
    }
    while (v.size())
    {
        t.push_back(v.back() * 10 + 6);
        ans.push_back(t.back());
        t.push_back(v.back() * 10 + 9);
        ans.push_back(t.back());
        v.pop_back();
    }
    while (t.size())
    {
        v.push_back(t.back() * 10 + 6);
        ans.push_back(v.back());
        v.push_back(t.back() * 10 + 9);
        ans.push_back(v.back());
        t.pop_back();
    }
    while (v.size())
    {
        t.push_back(v.back() * 10 + 6);
        ans.push_back(t.back());
        t.push_back(v.back() * 10 + 9);
        ans.push_back(t.back());
        v.pop_back();
    }
    while (t.size())
    {
        v.push_back(t.back() * 10 + 6);
        ans.push_back(v.back());
        v.push_back(t.back() * 10 + 9);
        ans.push_back(v.back());
        t.pop_back();
    }
    while (v.size())
    {
        t.push_back(v.back() * 10 + 6);
        ans.push_back(t.back());
        t.push_back(v.back() * 10 + 9);
        ans.push_back(t.back());
        v.pop_back();
    }
    while (t.size())
    {
        v.push_back(t.back() * 10 + 6);
        ans.push_back(v.back());
        v.push_back(t.back() * 10 + 9);
        ans.push_back(v.back());
        t.pop_back();
    }
    while (v.size())
    {
        t.push_back(v.back() * 10 + 6);
        ans.push_back(t.back());
        t.push_back(v.back() * 10 + 9);
        ans.push_back(t.back());
        v.pop_back();
    }
    while (t.size())
    {
        v.push_back(t.back() * 10 + 6);
        ans.push_back(v.back());
        v.push_back(t.back() * 10 + 9);
        ans.push_back(v.back());
        t.pop_back();
    }
    while (v.size())
    {
        t.push_back(v.back() * 10 + 6);
        ans.push_back(t.back());
        t.push_back(v.back() * 10 + 9);
        ans.push_back(t.back());
        v.pop_back();
    }
    while (t.size())
    {
        v.push_back(t.back() * 10 + 6);
        ans.push_back(v.back());
        v.push_back(t.back() * 10 + 9);
        ans.push_back(v.back());
        t.pop_back();
    }
    while (v.size())
    {
        t.push_back(v.back() * 10 + 6);
        ans.push_back(t.back());
        t.push_back(v.back() * 10 + 9);
        ans.push_back(t.back());
        v.pop_back();
    }
    while (t.size())
    {
        v.push_back(t.back() * 10 + 6);
        ans.push_back(v.back());
        v.push_back(t.back() * 10 + 9);
        ans.push_back(v.back());
        t.pop_back();
    }
    while (v.size())
    {
        t.push_back(v.back() * 10 + 6);
        ans.push_back(t.back());
        t.push_back(v.back() * 10 + 9);
        ans.push_back(t.back());
        v.pop_back();
    }
    while (t.size())
    {
        v.push_back(t.back() * 10 + 6);
        ans.push_back(v.back());
        v.push_back(t.back() * 10 + 9);
        ans.push_back(v.back());
        t.pop_back();
    }
    while (v.size())
    {
        t.push_back(v.back() * 10 + 6);
        ans.push_back(t.back());
        t.push_back(v.back() * 10 + 9);
        ans.push_back(t.back());
        v.pop_back();
    }
    sort(all(ans));
}
void solve(void)
{
    int l, r;
    cin >> l >> r;
    int x = lower_bound(all(ans), l) - ans.begin();
    int y = upper_bound(all(ans), r) - ans.begin();
    cout << max(0LL, y - x) << '\n';
}
//-----------------------------------------------------------------------------------------
signed main()
{
    // cout << fixed << showpoint << setprecision(10);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ok();
    int test = 1, T;
    cin >> test;
    for (T = 1; T <= test; T++)
    {
        // cout << "Case " << T << ": ";
        solve();
    }
    return 0;
}