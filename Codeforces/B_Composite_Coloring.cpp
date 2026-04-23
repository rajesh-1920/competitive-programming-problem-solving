// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  07.02.2025

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
    int n;
    cin >> n;
    vector<int> v(n), ans(n);
    int arr[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    set<int> st;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        for (int j = 0; j < 11; j++)
        {
            if (v[i] % arr[j] == 0)
            {
                ans[i] = j;
                st.insert(j);
                break;
            }
        }
    }
    map<int, int> mp;
    int cnt = 1;
    for (auto it : st)
        mp[it] = cnt++;
    cout << st.size() << '\n';
    for (auto it : ans)
        cout << mp[it] << ' ';
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