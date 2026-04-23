// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  11.09.2025

#include <bits/stdc++.h>
using namespace std;
//----------------------------(definition section)-----------------------------------------
#define dbg(x) cout << #x << " = " << x << '\n';
#define int long long int
#define fi first
#define sc second

#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()

const double eps = 1e-1;
const int inf = 9e16 + 7;
const int MOD = 1e9 + 7;
const int N = 1e6 + 10;
//------------------------------(solve)----------------------------------------------------
void ok(vector<int> &v, vector<int> &lln, vector<int> &llst)
{
    v[1] = 1;
    int ln = 2, lst = 2, len = 3;
    for (int i = 2; i < N; i++)
    {
        v[i] = i * i;
        if (i - ln + 1 < lst)
            v[i] += v[i - ln + 1];
        lln[i] = ln, llst[i] = lst;
        if (i == len)
            len = i + 1 + ln, lst = i + 1, ln++;
    }
}
void solve(vector<int> &v, vector<int> &lln, vector<int> &llst)
{
    int n;
    cin >> n;
    int ans = v[n], ln = lln[n], lst = llst[llst[n] - 1];
    while (true)
    {
        if (n - ln < lst)
            break;
        n -= ln;
        ans += v[n];
        ln = lln[n], lst = llst[llst[n] - 1];
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
    vector<int> v(N), lln(N), llst(N);
    ok(v, lln, llst);
    cin >> test;
    for (T = 1; T <= test; T++)
    {
        // cout << "Case " << T << ": ";
        solve(v, lln, llst);
    }
    return 0;
}