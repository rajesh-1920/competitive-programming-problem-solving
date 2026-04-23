// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  01.06.2025

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
void solve(void)
{
    int n, m;
    cin >> n >> m;
    string s;
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    for (int i = 2; v.size() < 10; i++)
        v.push_back(v.back() + v[v.size() - 2]);
    while (m--)
    {
        int w, l, h;
        cin >> w >> l >> h;
        if (l >= v[n - 1] && w >= v[n - 1] && v[n - 1] + v[n - 2] <= h)
        {
            s.push_back('1');
            continue;
        }
        swap(h, l);
        if (l >= v[n - 1] && w >= v[n - 1] && v[n - 1] + v[n - 2] <= h)
        {
            s.push_back('1');
            continue;
        }
        swap(h, l);
        swap(h, w);
        if (l >= v[n - 1] && w >= v[n - 1] && v[n - 1] + v[n - 2] <= h)
        {
            s.push_back('1');
            continue;
        }
        s.push_back('0');
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