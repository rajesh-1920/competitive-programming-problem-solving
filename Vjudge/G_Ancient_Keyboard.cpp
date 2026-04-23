// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  02.01.2025

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
    cin >> s;
    map<char, ll> mp;
    ll cur;
    for (ll i = 0; i < 26; i++)
    {
        mp[s[i]] = i;
        if (s[i] == 'A')
            cur = i;
    }
    set<char> st;
    for (ll i = 1; i < 26; i++)
    {
        char ch = char('A' + i);
        st.insert(ch);
    }
    ll ans = 0;
    while (!st.empty())
    {
        char ch = *st.begin();
        st.erase(st.begin());
        ll pos = mp[ch];
        ans += max((pos - cur), (-pos + cur));
        cur = mp[ch];
    }
    cout << ans;
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