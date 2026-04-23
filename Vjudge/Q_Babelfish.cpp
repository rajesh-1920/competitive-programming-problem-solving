// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  31.01.2025

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
//----------------------------(definition section)-----------------------------------------
#define dbg(x) cout << #x << " = " << x << '\n'
#define fi first
#define sc second

#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()

const double eps = 1e-1;
const ll inf = 9e15 + 7;
const ll MOD = 1e9 + 7;
const ll N = 1e9 + 10;
//-----------------------------------------------------------------------------------------
void solve(void)
{
    string s;
    map<string, string> mp;
    int ft = 0;
    while (getline(cin, s))
    {
        if (s.size() == 0)
            continue;
        string t1, t2;
        ll fl = 0;
        for (auto it : s)
        {
            if (it == ' ')
            {
                fl = 1;
                continue;
            }
            if (fl)
                t2.push_back(it);
            else
                t1.push_back(it);
        }
        if (t2.size() == 0)
        {
            ft = 1;
            if (mp.find(s) == mp.end())
                cout << "eh\n";
            else
                cout << mp[s] << '\n';
        }
        else
            mp[t2] = t1;
    }
}
//-----------------------------------------------------------------------------------------
int main()
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