// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  21.01.2025

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
    ll n;
    cin >> n;
    map<string, ll> mp;
    map<string, ll> pre;
    while (n--)
    {
        string s;
        cin >> s;
        if (mp[s] == 0)
        {
            cout << "OK\n";
            mp[s]++;
            pre[s] = 0;
            continue;
        }
        for (ll i = pre[s] + 1;; i++)
        {
            string t = to_string(i);
            string temp = s + t;
            if (mp[temp] == 0)
            {
                pre[s] = i;
                cout << temp << '\n';
                mp[temp]++;
                break;
            }
        }
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