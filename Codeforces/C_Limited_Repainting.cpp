// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  27.02.2025

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
const int N = 3e5 + 10;
//-----------------------------------------------------------------------------------------
int k, sz = 0;
bool isPossible(int penalty, string &s, vector<int> &a)
{
    int operations = 0;
    int i = 0;
    while (i < sz)
    {
        if (s[i] == 'B' && a[i] > penalty)
        {
            operations++;
            i++;
            while (i < sz && (s[i] == 'B' || a[i] <= penalty))
                i++;
        }
        else
            i++;
    }
    return operations <= k;
}
//-----------------------------------------------------------------------------------------
void solve(void)
{
    int n;
    string s, tm;
    cin >> n >> k >> tm;
    vector<int> tt(n), v;
    for (auto &it : tt)
        cin >> it;

    int r = tt[0];
    s.push_back(tm[0]);
    v.push_back(tt[0]);
    for (int i = 1; i < n; i++)
    {
        r = max(tt[i], r);
        if (tm[i] == s[s.size() - 1])
            v[s.size() - 1] = max(tt[i], v[s.size() - 1]);
        else
        {
            s.push_back(tm[i]);
            v.push_back(tt[i]);
        }
    }

    sz = v.size();
    int l = 0;
    int result = r;
    while (l <= r)
    {
        //dbg(result);
        int mid = l + (r - l) / 2;
        if (isPossible(mid, s, v))
        {
            result = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout << result << '\n';
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