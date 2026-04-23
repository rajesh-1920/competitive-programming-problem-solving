
#include <bits/stdc++.h>
using namespace std;
//----------------------------(definition section)-------------------------------------
#define ll long long int
#define rsrt(X) sort(X.rbegin(), X.rend())
#define srt(X) sort(X.begin(), X.end())

#define pa pair<ll, ll>
#define vec vector<ll>
#define vecp vector<pa>
#define fi first
#define sc second
#define pb(x) push_back(x)
#define ppb(x, y) push_back({x, y})

#define No cout << "No\n"
#define Yes cout << "Yes\n"
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define nl cout << "\n"
#define rrr return
//------------------------------------------------------------------------------------
void solve(void)
{
    ll n, m, i, cnt = 0;
    cin >> n;
    map<ll, ll> mp;
    for (i = 0; i < n; i++)
    {
        cin >> m;
        mp[m]++;
    }
    cin >> m;
    ll b[m];
    for (i = 0; i < m; i++)
        cin >> b[i];
    sort(b, b + m);
    for (i = 0; i < m; i++)
    {
        if (mp[b[i] - 1] > 0)
        {
            cnt++;
            mp[b[i] - 1]--;
        }
        else if (mp[b[i]] > 0)
        {
            cnt++;
            mp[b[i]]--;
        }
        else if (mp[b[i] + 1] > 0)
        {
            cnt++;
            mp[b[i] + 1]--;
        }
    }
    cout << cnt;
    nl;
}
//------------------------------------------------------------------------------------
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll test = 1;
    // cin >> test;
    while (test--)
        solve();
    return 0;
}