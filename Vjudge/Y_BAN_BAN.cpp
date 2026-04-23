// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  22.03.2025

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
    int n;
    cin >> n;
    int t = n;
    string s = "";
    set<int> a;
    vector<int> b;
    int k = 2;
    // for (int i = 0; i < n; i++)
    //     s += "BAN";
    for (int i = 0; i < n; i++)
    {
        a.insert(k);
        b.push_back(k + 1);
        k += 3;
    }

    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        int t1 = b.back();
        int t2 = *a.begin();
        if (t1 < t2)
            break;
        v.push_back({t2, t1});
        a.erase(a.begin());
        b.pop_back();
    }
    cout << v.size() << '\n';
    for (auto it : v)
    {
        cout << it.fi << ' ' << it.sc << '\n';
        // swap(s[it.fi - 1], s[it.sc - 1]);
    }
    // cout << s << '\n';
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