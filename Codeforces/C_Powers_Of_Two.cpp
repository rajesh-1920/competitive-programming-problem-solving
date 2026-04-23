// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  27.08.2025

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
    int n, k;
    cin >> n >> k;
    priority_queue<int> pq;
    for (int i = 0; i < 32; i++)
        if (n & (1 << i))
            pq.push(i);
    while (pq.size() < k)
    {
        int t = pq.top();
        if (t == 0)
            break;
        pq.pop();
        pq.push(t - 1);
        pq.push(t - 1);
    }
    if (pq.size() != k)
        cout << "NO\n";
    else
    {
        cout << "YES\n";
        while (pq.size())
        {
            int t = pq.top();
            pq.pop();
            cout << (1LL << t) << ' ';
        }
    }
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