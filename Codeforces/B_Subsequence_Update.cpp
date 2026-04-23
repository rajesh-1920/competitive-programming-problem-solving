// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  22.01.2025

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
const ll N = 1e5 + 10;
//-----------------------------------------------------------------------------------------
void solve(void)
{
    ll n, l, r;
    cin >> n >> l >> r;
    vector<ll> v(n);
    multiset<ll> stp, stn, stl, str;
    ll i = 1;
    for (auto &it : v)
    {
        cin >> it;
        if (i >= l && i <= r)
        {
            stl.insert(it);
            str.insert(it);
        }
        else
        {
            if (i < l)
                stp.insert(it);
            else
                stn.insert(it);
        }
    }
    while (true)
    {
        if (stp.size() == 0)
            break;
        auto it = --stl.end();
        auto itt = stp.begin();
        if (*it > *itt)
        {
            stl.erase(it);
            stl.insert(*itt);
            stp.erase(itt);
        }
        else
            break;
    }
    while (true)
    {
        if (stn.size() == 0)
            break;
        auto it = --str.end();
        auto itt = stn.begin();
        if (*it > *itt)
        {
            str.erase(it);
            str.insert(*itt);
            stn.erase(itt);
        }
        else
            break;
    }

    ll an = 0;
    for (auto it : stl)
        an += it;
    ll an1 = 0;
    for (auto it : str)
        an1 += it;
    cout << min(an, an1) << '\n';
}
//-----------------------------------------------------------------------------------------
int main()
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