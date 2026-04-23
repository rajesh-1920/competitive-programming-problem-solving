// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  08.04.2025

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
bool isPossible(vector<int> &a, int &k, int &x)
{
    unordered_set<int> need;
    for (int i = 0; i < x; ++i)
        need.insert(i);
    int cnt = 0;
    unordered_set<int> curr;
    for (int it : a)
    {
        if (it < x)
            curr.insert(it);
        if (curr.size() == need.size())
        {
            cnt++;
            curr.clear();
        }
    }
    return cnt >= k;
}
void solve(void)
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &it : v)
        cin >> it;
    int ans = 0, low = 0, high = n + 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (isPossible(v, k, mid))
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << ans << '\n';
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