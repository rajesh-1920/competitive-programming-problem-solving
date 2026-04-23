// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  23.01.2025

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
    ll n, q;
    cin >> n >> q;
    vector<ll> event(300010, 0);
    vector<stack<ll>> kon_kon_event(n + 5);
    set<ll> st;
    ll ans = 0, ev = 0;
    while (q--)
    {
        ll t, x;
        cin >> t >> x;
        if (t == 1)
        {
            ans++;
            kon_kon_event[x].push(ev);
            st.insert(ev);
            event[ev++] = 1;
        }
        else if (t == 2)
        {
            while (!kon_kon_event[x].empty())
            {
                ll temp = kon_kon_event[x].top();
                kon_kon_event[x].pop();
                if (event[temp])
                    ans--;
                event[temp] = 0;
                st.erase(temp);
            }
        }
        else
        {
            stack<ll> sss;
            for (auto it : st)
            {
                if (it >= x)
                    break;
                if (event[it])
                    ans--;
                event[it] = 0;
                sss.push(it);
            }
            while (!sss.empty())
            {
                st.erase(sss.top());
                sss.pop();
            }
                }
        cout << ans << '\n';
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