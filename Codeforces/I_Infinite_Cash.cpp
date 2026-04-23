// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  29.04.2025

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
const int N = 1e4 + 10;
//-----------------------------------------------------------------------------------------
void solve(void)
{
    string ss, sd, sm;
    cin >> ss >> sd >> sm;
    int d = 0, t = 1;
    for (int i = sd.size() - 1; i >= 0; i--)
    {
        if (sd[i] == '1')
            d += t;
        if (d > N || t > N)
        {
            int ans = sm.size();
            string temp = "";
            while (ans)
            {
                if (ans & 1)
                    temp.push_back('1');
                else
                    temp.push_back('0');
                ans /= 2;
            }
            reverse(all(temp));
            cout << temp << '\n';
            return;
        }
        t *= 2;
    }
    for (int i = 0; i < d; i++)
    {
        if (sm.size() == 0)
        {
            int ans = i;
            string temp = "";
            while (ans)
            {
                if (ans & 1)
                    temp.push_back('1');
                else
                    temp.push_back('0');
                ans /= 2;
            }
            reverse(all(temp));
            cout << temp << '\n';
            return;
        }
        sm.pop_back();
    }
    int ans = d;
    reverse(all(sm));
    reverse(all(ss));
    for (int t = 0; t < N; t++)
    {
        while (sm.size() > ss.size())
            ss.push_back('0');
        while (sm.size() < ss.size())
            sm.push_back('0');
        int carry = 0;
        string newsm = "";
        for (int i = 0; i < sm.size(); i++)
        {
            if (carry)
            {
                if (sm[i] == '1' && ss[i] == '1')
                    newsm.push_back('1'), carry = 1;
                else if (sm[i] == '1' || ss[i] == '1')
                    newsm.push_back('0');
                else
                    newsm.push_back('1'), carry = 0;
            }
            else
            {
                if (sm[i] == '1' && ss[i] == '1')
                    newsm.push_back('0'), carry = 1;
                else if (sm[i] == '1' || ss[i] == '1')
                    newsm.push_back('1');
                else
                    newsm.push_back('0');
            }
        }
        if (carry)
            newsm.push_back('1');

            
        while (newsm.size())
        {
            if (newsm.back() == '1')
                break;
            newsm.pop_back();
        }

        reverse(all(newsm));
        { // check----------------------------------------------
            for (int i = 0; i < d; i++)
            {
                if (newsm.size() == 0)
                {
                    string temp = "";
                    while (ans)
                    {
                        if (ans & 1)
                            temp.push_back('1');
                        else
                            temp.push_back('0');
                        ans /= 2;
                    }
                    reverse(all(temp));
                    cout << temp << '\n';
                    return;
                }
                ans++;
                newsm.pop_back();
            }
        }
        sm = newsm;
        reverse(all(sm));
    }
    cout << "Infinite money!";
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