// Author:  Rajesh Biswas
// CF    :  rajesh_1920
// Date  :  29.04.2026

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
    for (auto &it : v)
        cin >> it;
    vector<int> temp;
    for (int i = 0; i + 1 < n; i++)
    {
        if (v[i] > v[i + 1])
            temp.push_back(i);
    }
    for (int i = 1; i < temp.size(); i++)
    {
        if (temp[i] - temp[i - 1] == 1)
        {
            temp.clear();
            break;
        }
    }
    for (auto &it : temp)
    {
        int x = (v[it] - v[it + 1] + 1) / 2;
        v[it] -= x;
        v[it + 1] += x;
    }
    for (int i = 0; i + 1 < n; i++)
    {
        if (v[i] > v[i + 1])
        {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
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
        // cout << "Case #" << T << ": ";
        solve();
    }
    return 0;
}