// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  05.01.2025

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
    string s;
    
    getline(cin, s);
    vector<string> v;
    string temp;
    for (auto it : s)
    {
        if (it == ' ')
        {
            ll cnt = 0;
            for (auto itt : temp)
                if (itt >= 'A' && itt <= 'Z')
                    cnt++;
            if (cnt != temp.size())
            {
                for (ll i = 1; i < temp.size(); i++)
                    temp[i] |= ' ';
            }
            temp[0] &= '_';
            v.push_back(temp);
            temp.clear();
        }
        else
            temp.push_back(it);
    }
    ll cnt = 0;
    for (auto itt : temp)
        if (itt >= 'A' && itt <= 'Z')
            cnt++;
    if (cnt != temp.size())
    {
        for (ll i = 1; i < temp.size(); i++)
            temp[i] |= ' ';
    }
    temp[0] &= '_';
    v.push_back(temp);
    temp.clear();

    for (auto it : v)
        cout << it << ' ';
    cout << '\n';
}
//-----------------------------------------------------------------------------------------
int main()
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