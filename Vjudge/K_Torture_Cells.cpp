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
ll w, h;
ll dx[] = {0, 0, 1, -1};
ll dy[] = {1, -1, 0, 0};
ll vis[25][25];
string gr[25];
bool isvalid(ll xx, ll yy)
{
    return (xx >= 0 && xx < h && yy >= 0 && yy < w);
}
void dfs(ll x, ll y)
{
    vis[x][y] = 1;
    for (ll i = 0; i < 4; i++)
    {
        ll xx = x + dx[i], yy = y + dy[i];
        if (isvalid(xx, yy))
            if (gr[xx][yy] == '.' && vis[xx][yy] == 0)
                dfs(xx, yy);
    }
}
void solve(void)
{
    for (ll i = 0; i < 25; i++)
        for (ll j = 0; j < 25; j++)
            vis[i][j] = 0;
    cin >> w >> h;
    ll x, y;
    for (ll i = 0; i < h; i++)
    {
        cin >> gr[i];
        for (ll j = 0; j < w; j++)
            if (gr[i][j] == '@')
            {
                x = i;
                y = j;
            }
    }
    dfs(x, y);
    ll ans = 0;
    for (ll i = 0; i < 25; i++)
        for (ll j = 0; j < 25; j++)
            if (vis[i][j] == 1)
                ans++;
    cout << ans << '\n';
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
        cout << "Case " << T << ": ";
        solve();
    }
    return 0;
}