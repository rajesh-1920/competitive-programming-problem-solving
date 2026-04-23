// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  25.03.2025

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
    getline(cin, s);
    map<string, int> mp;
    mp.insert({"zero", 0});
    mp.insert({"one", 1});
    mp.insert({"two", 2});
    mp.insert({"three", 3});
    mp.insert({"four", 4});
    mp.insert({"five", 5});
    mp.insert({"six", 6});
    mp.insert({"seven", 7});
    mp.insert({"eight", 8});
    mp.insert({"nine", 9});
    mp.insert({"ten", 10});
    mp.insert({"eleven", 11});
    mp.insert({"twelve", 12});
    mp.insert({"thirteen", 13});
    mp.insert({"fourteen", 14});
    mp.insert({"fifteen", 15});
    mp.insert({"sixteen", 16});
    mp.insert({"seventeen", 17});
    mp.insert({"eighteen", 18});
    mp.insert({"nineteen", 19});
    mp.insert({"twenty", 20});
    mp.insert({"thirty", 30});
    mp.insert({"forty", 40});
    mp.insert({"fifty", 50});
    mp.insert({"sixty", 60});
    mp.insert({"seventy", 70});
    mp.insert({"eighty", 80});
    mp.insert({"ninety", 90});
    mp.insert({"hundred", 100});
    mp.insert({"thousand", 1000});
    string t = "";
    vector<int> v;
    for (auto it : s)
    {
        if (it == ' ')
        {
            int x = mp[t];
            t = "";
            if (x == 1000)
            {
                x = v.back() * 1000;
                v.pop_back();
                v.push_back(x);
            }
            else if (x == 100)
            {
                x = v.back() * 100;
                v.pop_back();
                v.push_back(x);
            }
            else
                v.push_back(x);
        }
        else
            t.push_back(it);
    }
    int x = mp[t];
    if (x == 1000)
    {
        x = v.back() * 1000;
        v.pop_back();
        v.push_back(x);
    }
    else if (x == 100)
    {
        x = v.back() * 100;
        v.pop_back();
        v.push_back(x);
    }
    else
        v.push_back(x);
    x = 0;
    for (auto it : v)
    {
        // cout << it << ' ';
        x += it;
    }
    //cout << x << ' ';
    string c = "";
    if (x == 0)
    {
        cout << "YES\n";
        return;
    }
    while (x)
    {
        if (x & 1)
            c.push_back('1');
        else
            c.push_back('0');
        x /= 2;
    }
    int z = c.size() - 1;
    for (int i = 0; i < c.size(); i++)
    {
        if (c[i] != c[z])
        {
            cout << "NO\n";
            return;
        }
        z--;
    }
    cout << "YES\n";
}
//-----------------------------------------------------------------------------------------
signed main()
{
    // cout << fixed << showpoint << setprecision(10);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1, T;
    cin >> test;
    cin.ignore();
    for (T = 1; T <= test; T++)
    {
        // cout << "Case " << T << ": ";
        solve();
    }
    return 0;
}