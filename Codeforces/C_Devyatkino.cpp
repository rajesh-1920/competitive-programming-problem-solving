// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  11.02.2025

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
const int MOD = 1e10 + 7;
const int N = 1e5 + 10;
//-----------------------------------------------------------------------------------------
int is_seven(int n)
{
    while (n)
    {
        int x = n - (n / 10) * 10;
        if (x == 7)
            return 1;
        n /= 10;
    }
    return 0;
}
int arr[] = {9,
             99,
             999,
             9999,
             99999,
             999999,
             9999999,
             99999999,
             999999999,
             9999999999};
// map<pair<int, pair<int, int>>, int> mp;
int ok(int n, int ind, int cnt)
{
    /*if (cnt > 7 || ind > 9)
        return inf;
    if (is_seven(n))
        return cnt;
    if (mp.find({n, {ind, cnt}}) != mp.end())
        return mp[{n, {ind, cnt}}];
    int ans = ok(n, ind + 1, cnt);
    for (int i = 0; i < 7; i++)
    {
        ans = min(ans, ok(n + arr[ind], ind, cnt + 1));
    }
    return mp[{n, {ind, cnt}}] = ans;*/
    int ans = 7;
    if (is_seven(n))
        ans = 0;
    for (int i = 0; i < 10; i++)
    {
        int x = n;
        for (int j = 0; j < 7; j++)
        {
            x += arr[i];
            if (is_seven(x))
                ans = min(ans, j + 1);
            // dbg(n + arr[i]);
        }
    }
    return ans;
}
//-----------------------------------------------------------------------------------------
void solve(void)
{
    int n;
    cin >> n;
    cout << ok(n, 0, 0) << '\n';
    // mp.clear();
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