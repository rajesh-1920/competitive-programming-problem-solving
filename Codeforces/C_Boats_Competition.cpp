// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  26.04.2026

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
    multiset<int>temp;
    for(int i=0;i<n;i++)
    {
      int x;
      cin>>x;
      temp.insert(x);
    }
    int ans=0;
    for(int i=2;i<=100;i++)
    {
       multiset<int>st;
       for(auto it:temp)
          st.insert(it);
          int cnt=0;
       while(st.size()>1)
       {
          int x=i-(*st.begin());
          if(x<1)
          break;
          st.erase(st.begin());
          if(st.find(x)!=st.end())
          {
             cnt++;
             st.erase(st.find(x));
          }
       } 
       ans=max(ans,cnt);
    }
    cout << ans << endl;
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