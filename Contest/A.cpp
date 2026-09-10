// Author:  Rajesh Biswas
// CF    :  rajesh_1920

#include <bits/stdc++.h>
using namespace std;
//----------------------------(definition section)-----------------------------------------
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
#define Dbg(x) cout << #x << ' ' << " = " << x << '\n';
template <class T>
void dbg(T x)
{
    cout << x << ' ';
}
template <class T, class V>
void dbg(pair<T, V> x)
{
    cout << "{";
    dbg(x.first);
    dbg(x.second);
    cout << "},";
}
template <class T>
void dbg(vector<T> x)
{
    cout << "[";
    for (auto &it : x)
        dbg(it);
    cout << "]\n";
}
template <class T>
void dbg(set<T> x)
{
    cout << "[";
    for (auto &it : x)
        dbg(it);
    cout << "]\n";
}
template <class T>
void dbg(multiset<T> x)
{
    cout << "[";
    for (auto &it : x)
        dbg(it);
    cout << "]\n";
}
template <class T, class V>
void dbg(map<T, V> x)
{
    cout << "[";
    for (auto &it : x)
        dbg(it);
    cout << "]\n";
}
template <class T>
void dbg(stack<T> x)
{
    cout << "[";
    while (!x.empty())
        dbg(x.top()), x.pop();
    cout << "]\n";
}
template <class T>
void dbg(queue<T> x)
{
    cout << "[";
    while (!x.empty())
        dbg(x.front()), x.pop();
    cout << "]\n";
}
//------------------------------(solve)----------------------------------------------------
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &it : v)
        cin >> it;
    int ans = 0;
    if (n % 8 == 7)
        for (int i = 0; i < n; i += 2)
            ans ^= v[i];
    else if (n % 8 == 5)
    {
        ans ^= v[0];
        ans ^= v[4];
        if (n > 5)
        {
            ans ^= v[n - 4];
            ans ^= v[n - 1];
        }
    }
    else if (n % 8 == 3)
    {
        ans ^= v[0];
        ans ^= v[2];
        if (n > 3)
        {
            ans ^= v[n - 3];
            ans ^= v[n - 1];
        }
    }
    else if (n % 8 == 1)
    {
        ans = v.front() ^ v.back();
    }
    else if (n % 8 == 0)
        for (auto &it : v)
            ans ^= it;
    else if (n % 8 == 2)
    {
        ans ^= v[0];
        ans ^= v[1];
        if (n > 3)
        {
            ans ^= v[n - 2];
            ans ^= v[n - 1];
        }
    }
    else if (n % 8 == 4)
    {
        ans ^= v[0];
        ans ^= v[1];
        ans ^= v[2];
        ans ^= v[3];
        if (n > 4)
        {
            ans ^= v[n - 4];
            ans ^= v[n - 3];
            ans ^= v[n - 2];
            ans ^= v[n - 1];
        }
    }
    else if (n % 8 == 6)
    {
        ans ^= v[0];
        ans ^= v[1];
        ans ^= v[4];
        ans ^= v[5];
        if (n > 4)
        {
            ans ^= v[n - 6];
            ans ^= v[n - 5];
            ans ^= v[n - 2];
            ans ^= v[n - 1];
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
        // cout << "Case #" << T << ":\n";
        solve();
    }
    return 0;
}