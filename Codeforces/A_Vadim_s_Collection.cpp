// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  24.04.2025

#include <bits/stdc++.h>
using namespace std;
//----------------------------(definition section)-----------------------------------------
#define dbg(x) cout << #x << " = " << x << '\n'
#define int long long int
#define fi first
#define sc second

#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()

const double eps = 1e-1;
const int inf = 9e16 + 7;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;
//-----------------------------------------------------------------------------------------
void solve(void)
{
    string s;
    cin >> s;
    priority_queue<char> pq;
    for (auto it : s)
        pq.push(it);
    multiset<char> tm, st;
    int cnt = 1;
    while (!pq.empty())
    {
        int t = pq.top() - '0';
        if (t >= (10 - cnt))
        {
            if (st.find(pq.top()) == st.end())
            {
                cout << pq.top();
                cnt++;
                st.insert(pq.top());
            }
            else
                tm.insert(pq.top());
        }
        else
            tm.insert(pq.top());
        pq.pop();
    }
    while (!tm.empty())
    {
        for (auto it : tm)
        {
            int t = it - '0';
            if (t >= (10 - cnt))
            {
                cout << it;
                cnt++;
                tm.erase(tm.find(it));
                break;
            }
        }
    }
    cout << '\n';
}
//-------------------------------------------------------------------------------------------
signed main()
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