// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  30.05.2025

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
const int inf = 1e15 + 7;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;
//-----------------------------------------------------------------------------------------
void solve(void)
{
    int n, k;
    string s;
    cin >> n >> k >> s;

    vector<int> v(n + 2);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    s = "0" + s + "0";
    for (int i = 0; i <= n + 1; i++)
        if (s[i] == '0')
            v[i] = -inf;

    int fl = 1;
    for (int i = 1; i <= n; i++)
    {
        if (v[i] == -inf)
        {
            int lcont = 0, rcont = 0, mx = 0;
            int l;
            for (int j = i - 1;; j--)
                if (v[j] == -inf)
                {
                    l = j;
                    break;
                }
            for (int j = l; j < i; j++)
            {
                lcont += v[j];
                mx = max(mx, lcont);
                lcont = max(lcont, 0LL);
            }

            if (mx > k)
                continue;
            int r;
            for (int j = i + 1;; j++)
                if (v[j] == -inf)
                {
                    r = j;
                    break;
                }
            mx = 0;
            for (int j = r; j > i; j--)
            {
                rcont += v[j];
                mx = max(mx, rcont);
                rcont = max(rcont, 0LL);
            }
            if (mx > k)
                continue;

            fl = 0;
            v[i] = k - lcont - rcont;
            break;
        }
    }
    int lcont = 0, mx = 0;
    for (int j = 1; j <= n; j++)
    {
        lcont += v[j];
        mx = max(mx, lcont);
        lcont = max(lcont, 0LL);
    }
    if (mx > k)
        fl = 1;
    else if (mx == k)
        fl = 0;
    if (fl)
        cout << "No\n";
    else
    {
        cout << "Yes\n";
        for (int i = 1; i <= n; i++)
            cout << v[i] << ' ';
        cout << '\n';
    }
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