// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  11.04.2025

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
bool cmp(int a, int b)
{
    return a > b;
}
void solve(void)
{
    int n, q;
    string s;
    cin >> n >> q >> s;
    vector<int> v(n + 5, 0), an(n);
    for (int i = 0; i < n; i++)
        an[i] = s[i] - 'a';
    while (q--)
    {
        int x, y, t;
        cin >> x >> y >> t;
        x--;
        if (t == 1)
            sort(an.begin() + x, an.begin() + y);
        else
            sort(an.begin() + x, an.begin() + y, cmp);
    }
    for (int i = 0; i < n; i++)
    {
        char ch = ('a' + an[i]);
        cout << ch;
    }
}
//-----------------------------------------------------------------------------------------
signed main()
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