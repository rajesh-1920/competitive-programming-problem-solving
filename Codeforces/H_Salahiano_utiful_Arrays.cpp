// Author:  Rajesh Biswas
// CF    :  rajesh19
// Date  :  07.11.2024

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
//------------------------------------------------------------------------------------------
/*/----------------------------(Order_set)--------------------------------------------------
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
o_set<ll> s;
//---------------------------------------------------------------------------------------*/
/*/-------------------------Modular-Arithmatic----------------------------------------------
inline ll _normal(ll A, ll M)
{
    A = A - (A / M) * M;
    if (A < 0)
        A += M;
    return A;
}
inline ll modadd(ll A, ll B, ll M)
{
    A = _normal(A, M), B = _normal(B, M);
    return _normal(A + B, M);
}
inline ll modsub(ll A, ll B, ll M)
{
    A = _normal(A, M), B = _normal(B, M);
    return _normal(A - B, M);
}
inline ll modmul(ll A, ll B, ll M)
{
    A = _normal(A, M), B = _normal(B, M);
    return _normal(A * B, M);
}
inline ll binexpo(ll A, ll B, ll M)
{
    ll ans = _normal(1, M);
    while (B)
    {
        if (B & 1)
            ans = modmul(ans, A, M);
        A = modmul(A, A, M);
        B >>= 1;
    }
    return _normal(ans, M);
}
inline ll moddiv(ll A, ll B, ll M)
{
    A = _normal(A, M), B = _normal(B, M);
    return _normal(modmul(A, (binexpo(B, M - 2, M)), M), M);
}
//-----------------------------------------------------------------------------------------*/
//----------------------------(definition section)-------------------------------------------
#define f(i, a, b) for (ll i = a; i < b; i++)
#define scv(v, n) f(i, 0, n) cin >> (v[i]);
#define dbg(x) cout << #x << " = " << x << '\n'
#define nl cout << ("\n")
#define rrr return
#define fi first
#define sc second
#define pb(x) push_back(x)
#define ppb(x, y) push_back({x, y})

#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()

#define PI acos(-1)
#define base1 1000002089
#define base2 1000003853
#define hashmod 1000002989

#define eps 0.0000000001
#define inf 90000000000000
#define MOD 1000000007
#define N 200009
//------------------------------------------------------------------------------------------
vector<ll> b(N), a(N);
set<ll> pos_a[N], pos_b[N];

void solve(void)
{
    ll n;
    cin >> n;
    ll fl = 0;
    map<ll, ll> mpa, mpb;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
        mpa[a[i]]++;
        mpb[b[i]]++;
        pos_a[a[i]].insert(i);
        pos_b[b[i]].insert(i);
        if (mpa[a[i]] > 2 || mpb[a[i]] > 2)
            fl = 1;
    }
    if (fl)
    {
        cout << -1 << '\n';
        return;
    }
    ll cnt = 0;
    for (ll i = 0; i < n; i++)
    {
        if (pos_a[a[i]].size() == 2)
        {
            ll x = *(pos_a[a[i]].begin());
            pos_a[a[i]].erase(pos_a[a[i]].begin());
            ll y = *(pos_a[a[i]].begin());
            pos_a[a[i]].erase(pos_a[a[i]].begin());

            if (mpa[b[x]] == 0 && mpb[a[x]] == 0)
            {
                mpa[a[x]]--;
                mpb[b[x]]--;
                mpa[b[x]]++;
                mpb[a[x]]++;
                pos_b[b[x]].erase(x);
                pos_b[a[x]].insert(x);
                pos_a[b[x]].insert(x);
                pos_a[a[x]].insert(y);
                cnt++;
            }
            else
            {
                swap(x, y);
                if (mpa[b[x]] == 0 && mpb[a[x]] == 0)
                {
                    mpa[a[x]]--;
                    mpb[b[x]]--;
                    mpa[b[x]]++;
                    mpb[a[x]]++;
                    pos_b[b[x]].erase(x);
                    pos_b[a[x]].insert(x);
                    pos_a[b[x]].insert(x);
                    pos_a[a[x]].insert(y);
                    cnt++;
                }
                else
                {
                    cout << -1 << '\n';
                    return;
                }
            }
        }
    }
    cout << cnt << '\n';
}
//------------------------------------------------------------------------------------------
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
/*
freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
*/