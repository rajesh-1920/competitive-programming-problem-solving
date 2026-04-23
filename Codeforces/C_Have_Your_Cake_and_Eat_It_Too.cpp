// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  12.01.2025

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
    ll n, sum = 0;
    cin >> n;
    vector<ll> a(n), b(n), c(n);
    for (auto &it : a)
    {
        cin >> it;
        sum += it;
    }
    for (auto &it : b)
        cin >> it;
    for (auto &it : c)
        cin >> it;
    ll sma = 0, smb = 0, smc = 0, la = -1, ra = -1, lb = -1, rb = -1, lc = -1, rc = -1, tar = sum / 3;
    if (sum % 3)
        tar++;
    for (ll i = 0; i < n; i++)
    {
        sma += a[i];
        smb += b[i];
        smc += c[i];
        if (sma >= tar && la == -1)
        {
            if (lb == -1 && lc == -1)
                la = 1;
            else if (lb == -1)
                la = rc + 1;
            else
                la = rb + 1;
            ra = i + 1;
            sma = smb = smc = 0;
            // dbg(la);
        }
        else if (smb >= tar && lb == -1)
        {
            if (la == -1 && lc == -1)
                lb = 1;
            else if (la == -1)
                lb = rc + 1;
            else
                lb = ra + 1;
            rb = i + 1;
            sma = smb = smc = 0;
        }
        else if (smc >= tar && lc == -1)
        {
            if (la == -1 && lb == -1)
                lc = 1;
            else if (la == -1)
                lc = rb + 1;
            else
                lc = ra + 1;
            rc = i + 1;
            sma = smb = smc = 0;
        }
    }

    if (la == -1 || lb == -1 || lc == -1)
        cout << -1 << '\n';
    else
        cout << la << ' ' << ra << ' ' << lb << ' ' << rb << ' ' << lc << ' ' << rc << '\n';
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