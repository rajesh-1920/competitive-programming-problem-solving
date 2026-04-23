// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  17.10.2025

#include <bits/stdc++.h>
using namespace std;
//----------------------------(definition section)-----------------------------------------
#define dbg(x) cout << #x << " = " << x << '\n';
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
    string s;
    cin >> n >> s;
    priority_queue<pair<int, string>> ans;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            int len = i;
            vector<int> temp[26], barti;
            for (int i = 0; i < n; i++)
                temp[s[i] - 'a'].push_back(i);

            priority_queue<pair<int, int>> pq;
            for (int i = 0; i < 26; i++)
            {
                if (temp[i].size() < len)
                    pq.push({temp[i].size(), i});
                while (temp[i].size() > len)
                    barti.push_back(temp[i].back()), temp[i].pop_back();
            }
            int fl = 0;
            while (barti.size())
            {
                if (pq.empty())
                {
                    fl = 1;
                    break;
                }
                int t = pq.top().sc;
                pq.pop();
                temp[t].push_back(barti.back());
                barti.pop_back();
                if (temp[t].size() < len)
                    pq.push({temp[t].size(), t});
            }
            if (fl)
                continue;
            set<pair<int, int>> st;
            for (int i = 0; i < 26; i++)
            {
                if (temp[i].size() < len && temp[i].size())
                    st.insert({temp[i].size(), i});
            }
            while (st.size())
            {
                int last = (*(--st.end())).sc;
                st.erase(--st.end());
                int fst = (*st.begin()).sc;
                st.erase(st.begin());
                temp[last].push_back(temp[fst].back());
                temp[fst].pop_back();
                if (temp[fst].size())
                    st.insert({temp[fst].size(), fst});
                if (temp[last].size() < len)
                    st.insert({temp[last].size(), last});
            }
            int cn = 0;
            string xc = s;
            for (int i = 0; i < 26; i++)
            {
                for (auto ii : temp[i])
                {
                    cn += (s[ii] != char(i + 'a'));
                    xc[ii] = char(i + 'a');
                }
            }
            ans.push({-cn, xc});
        }
    }
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            int len = n / i;
            vector<int> temp[26], barti;
            for (int i = 0; i < n; i++)
                temp[s[i] - 'a'].push_back(i);

            priority_queue<pair<int, int>> pq;
            for (int i = 0; i < 26; i++)
            {
                if (temp[i].size() < len)
                    pq.push({temp[i].size(), i});
                while (temp[i].size() > len)
                    barti.push_back(temp[i].back()), temp[i].pop_back();
            }
            int fl = 0;
            while (barti.size())
            {
                if (pq.empty())
                {
                    fl = 1;
                    break;
                }
                int t = pq.top().sc;
                pq.pop();
                temp[t].push_back(barti.back());
                barti.pop_back();
                if (temp[t].size() < len)
                    pq.push({temp[t].size(), t});
            }
            if (fl)
                continue;
            set<pair<int, int>> st;
            for (int i = 0; i < 26; i++)
            {
                if (temp[i].size() < len && temp[i].size())
                    st.insert({temp[i].size(), i});
            }
            while (st.size())
            {
                int last = (*(--st.end())).sc;
                st.erase(--st.end());
                int fst = (*st.begin()).sc;
                st.erase(st.begin());
                temp[last].push_back(temp[fst].back());
                temp[fst].pop_back();
                if (temp[fst].size())
                    st.insert({temp[fst].size(), fst});
                if (temp[last].size() < len)
                    st.insert({temp[last].size(), last});
            }
            int cn = 0;
            string xc = s;
            for (int i = 0; i < 26; i++)
            {
                for (auto ii : temp[i])
                {
                    cn += (s[ii] != char(i + 'a'));
                    xc[ii] = char(i + 'a');
                }
            }
            ans.push({-cn, xc});
        }
    }
    cout << -ans.top().fi << '\n'
         << ans.top().sc << '\n';
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