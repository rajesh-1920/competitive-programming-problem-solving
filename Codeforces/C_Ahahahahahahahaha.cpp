// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  19.10.2025

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
    int n;
    cin >> n;
    vector<int> v(n);
    set<int> ev, od;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if (v[i])
            if (i & 1)
                od.insert(i);
            else
                ev.insert(i);
    }
    for (int i = 0; i < n; i++)
    {
        if (i + 1 < n && v[i] == v[i + 1])
        {
            if (ev.find(i) != ev.end())
                ev.erase(i);
            if (ev.find(i + 1) != ev.end())
                ev.erase(i + 1);
            if (od.find(i) != od.end())
                od.erase(i);
            if (od.find(i + 1) != od.end())
                od.erase(i + 1);
            i++;
        }
    }
    while (ev.size() != od.size())
    {
        int pos;
        if (ev.size() > od.size())
            pos = *ev.begin();
        else
            pos = *od.begin();
        vector<int> temp;
        for (int i = 0; i < v.size(); i++)
            if (i != pos)
                temp.push_back(v[i]);
        v = temp;
        od.clear(), ev.clear();
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i])
                if (i & 1)
                    od.insert(i);
                else
                    ev.insert(i);
        }
        for (int i = 0; i < v.size(); i++)
        {
            if (i + 1 < v.size() && v[i] == v[i + 1])
            {
                if (ev.find(i) != ev.end())
                    ev.erase(i);
                if (ev.find(i + 1) != ev.end())
                    ev.erase(i + 1);
                if (od.find(i) != od.end())
                    od.erase(i);
                if (od.find(i + 1) != od.end())
                    od.erase(i + 1);
                i++;
            }
        }
    }
    cout << v.size() << '\n';
    for (auto it : v)
        cout << it << ' ';
    cout << '\n';
}
//-----------------------------------------------------------------------------------------
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