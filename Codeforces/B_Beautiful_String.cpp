// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  17.10.2025

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
const int N = 1e5 + 10;
//------------------------------(solve)----------------------------------------------------
bool isok(const string &s)
{
    string t = s;
    reverse(all(t));
    return s == t;
}

bool issort(const string &s)
{
    for (int i = 1; i < s.size(); i++)
        if (s[i] < s[i - 1])
            return false;
    return true;
}

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    for (int tt = 0; tt < (1 << n); tt++)
    {
        string p, x;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            if (tt & (1 << i))
            {
                p += s[i];
                v.push_back(i + 1);
            }
            else
                x += s[i];
        }
        if (issort(p) && isok(x))
        {
            cout << v.size() << '\n';
            for (int i = 0; i < v.size(); i++)
                cout << v[i] << ' ';
            cout << '\n';
            return;
        }
    }
    cout << -1 << '\n';
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