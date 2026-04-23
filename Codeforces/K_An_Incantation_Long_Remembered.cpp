#include <bits/stdc++.h>
#define FAST_IO                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define all(x) (x).begin(), (x).end()
using namespace std;
#define int long long

signed main()
{
    FAST_IO;
    // start
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];

        string s;
        cin >> s;

        stack<string> q;
        bool fnd = false;
        int cnt = 0;

        for (int i = 0; i < s.size(); i++)
        {
            bool ok = true;
            for (int j = 0; j < n; j++)
            {
                if (s[i] == v[j][0])
                {
                    //cout<<"OK " <<i<<'\n';
                    ok = false;
                    int idx = 1;
                    string r;
                    r.push_back(v[j][0]);
                    while (i + 1 < s.size() && idx < v[j].size() && s[i + 1] == v[j][idx])
                    {
                        r.push_back(v[j][idx]);
                        i++;
                        idx++;
                    }
                    if (r.size() == v[j].size())
                    {
                       // cout<<r<<'\n';
                        cnt++;
                    }
                    else
                    {
                       // cout<<r<<'\n';
                        q.push(r);
                    }
                    break;
                }
            }
            if (ok && q.size() > 0)
            {
                string x = q.top();
                q.pop();
                //cout<<x<<'\n';
                for (int j = 0; j < n; j++)
                {
                    if (v[j][0] == x[0])
                    {
                        int idx = x.size();
                        if (idx < v[j].size() && v[j][idx] == s[i])
                        {
                            ok = false;
                            x.push_back(v[j][idx]);
                            idx++;
                            while (i + 1 < s.size() && idx < v[j].size() && s[i + 1] == v[j][idx])
                            {
                                x.push_back(v[j][idx]);
                                i++;
                                idx++;
                            }

                            if (x.size() == v[j].size())
                            {
                                cnt++;
                            }
                            else
                            {
                                q.push(x);
                            }
                        }
                        break;
                    }
                }
            }
            if (ok)
            {
                fnd = true;
                break;
            }
        }

        if (fnd || q.size() > 0)
        {
            cout << "NO" << '\n';
        }
        else
        {
            cout << "YES" << '\n';
            cout << cnt + 1 << '\n';
        }
    }

    return 0;
}