// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  19.10.2025

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
void solve(void)
{
    vector<string> day = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun",
                          "Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};
    int dl, hl, hr, ml, mr;
    string ddl, ddr;
    char ch;
    cin >> ddl >> hl >> ch >> ml >> ddr >> hr >> ch >> mr;
    for (int i = 0; i < day.size(); i++)
        if (day[i] == ddl)
        {
            dl = i;
            break;
        }
    int m = 0;
    while (!(day[dl] == ddr && hl == hr && ml == mr))
    {
        m++, ml++;
        if (ml == 60)
            hl++, ml = 0;
        if (hl == 24)
            dl++, hl = 0;
    }
    int d = m / (24 * 60);
    if (m == 0)
        d = 7;
    m %= (24 * 60);
    int h = m / 60;
    m %= 60;
    if (d && h && m)
        cout << d << (d > 1 ? " days" : " day") << ", "
             << h << (h > 1 ? " hours" : " hour") << ", "
             << m << (m > 1 ? " minutes" : " minute") << '\n';
    else if (d && h)
        cout << d << (d > 1 ? " days" : " day") << " and "
             << h << (h > 1 ? " hours" : " hour") << "\n";
    else if (d && m)
        cout << d << (d > 1 ? " days" : " day") << " and "
             << m << (m > 1 ? " minutes" : " minute") << '\n';
    else if (h && m)
        cout << h << (h > 1 ? " hours" : " hour") << " and "
             << m << (m > 1 ? " minutes" : " minute") << '\n';
    else if (d)
        cout << d << (d > 1 ? " days" : " day") << "\n";
    else if (h)
        cout << h << (h > 1 ? " hours" : " hour") << "\n";
    else if (m)
        cout << m << (m > 1 ? " minutes" : " minute") << '\n';
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