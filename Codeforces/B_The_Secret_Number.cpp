// // Author:  Rajesh Biswas
// // CF    :  rajesh-1920
// // Date  :  21.08.2025

// #include <bits/stdc++.h>
// using namespace std;
// //----------------------------(definition section)-----------------------------------------
// #define dbg(x) cout << #x << " = " << x << '\n'
// #define int long long int
// #define fi first
// #define sc second

// #define all(s) s.begin(), s.end()
// #define rall(s) s.rbegin(), s.rend()

// const double eps = 1e-1;
// const int inf = 9e16 + 7;
// const int MOD = 1e9 + 7;
// const int N = 1e5 + 10;
// //------------------------------(solve)----------------------------------------------------
// void solve(void)
// {
//     int n;
//     cin >> n;
//     vector<int> v;
//     string s1 = to_string(n);
//     sort(all(s1));
//     int sz = s1.size();
//     if (sz % 2 == 0 && s1.front() == s1.back())
//     {
//         for (int i = 1; i < 11; i++)
//         {
//             if (sz % i == 0 && ((sz - i) / i) & 1)
//             {
//                 string tt;
//                 int fl = 1, cnt = 0;
//                 while (tt.size() < sz - i)
//                 {
//                     if (fl)
//                         tt.push_back(s1.front());
//                     else
//                         tt.push_back('0');
//                     cnt++;
//                     if (cnt == i)
//                         cnt = 0, fl ^= 1;
//                 }
//                 v.push_back(stoll(tt));
//             }
//         }
//     }
//     sort(all(v));
//     cout << v.size() << '\n';
//     for (auto it : v)
//         cout << it << ' ';
//     if (v.size())
//         cout << '\n';
// }
// //-----------------------------------------------------------------------------------------
// signed main()
// {
//     // cout << fixed << showpoint << setprecision(10);
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int test = 1, T;
//     cin >> test;
//     for (T = 1; T <= test; T++)
//     {
//         // cout << "Case " << T << ": ";
//         solve();
//     }
//     return 0;
// }

// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  21.08.2025

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
//------------------------------(solve)----------------------------------------------------
void solve(void)
{
    int n;
    cin >> n;

    vector<int> ans, p10(25);
    p10[0] = 1;
    for (int i = 1; i <= 18; ++i)
        p10[i] = p10[i - 1] * 10;

    for (int k = 1; k <= 17; ++k)
    {
        int d = p10[k] + 1;
        if (d > n)
            break;
        if (n % d == 0)
            ans.push_back(n / d);
    }
    sort(all(ans));
    cout << ans.size() << '\n';
    for (auto it : ans)
        cout << it << ' ';
    if (ans.size())
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