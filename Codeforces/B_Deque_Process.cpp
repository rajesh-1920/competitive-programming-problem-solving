// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  27.07.2025

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
void solve(void)
{
    int n;
    cin >> n;
    vector<int> v(n), ans;
    for (auto &it : v)
        cin >> it;
    string s = "";
    s.push_back('L');
    ans.push_back(v[0]);
    int l = 1, r = n - 1;
    while (l <= r)
    {
        if (l == r)
        {
            s.push_back('L');
            break;
        }
        // dbg(v[l]);
        // dbg(v[r]);
        if (ans.back() > v[l])
        {
            if (v[r] > v[l])
            {
                s.push_back('L'), s.push_back('R');
                ans.push_back(v[l]), ans.push_back(v[r]);
            }
            else
            {
                s.push_back('R'), s.push_back('L');
                ans.push_back(v[r]), ans.push_back(v[l]);
            }
        }
        else
        {
            if (v[r] > v[l])
            {
                ans.push_back(v[r]), ans.push_back(v[l]);
                s.push_back('R'), s.push_back('L');
            }
            else
            {
                ans.push_back(v[l]), ans.push_back(v[r]);
                s.push_back('L'), s.push_back('R');
            }
        }
        r--, l++;
    }
    cout << s << '\n';
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