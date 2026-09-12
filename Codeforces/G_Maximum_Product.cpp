// Author:  Rajesh Biswas
// CF    :  rajesh_1920
// Date  :  11.09.2026

#include <bits/stdc++.h>
using namespace std;
//----------------------------(definition section)-----------------------------------------
#define Dbg(x) cout << #x << " = " << x << '\n'
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
  string s1,s2;
  cin>>s1>>s2;
  string ans,temp=s2;
  reverse(all(s1));
  reverse(all(s2));
  while(s1.size()<s2.size())s1.push_back('0');
  while(s1.size()>s2.size())s2.push_back('0');
  while(!s1.empty()&&s1.back()==s2.back()){
    ans.push_back(s1.back());
    s1.pop_back(),s2.pop_back();
  }
  if(s1.size()==1){
    ans.push_back(char(s2.back()));
    s1.pop_back(),s2.pop_back();
  }
  else if(!s1.empty()){
    if(s2.back()!='1')
      ans.push_back(char(s2.back()-1));
    s1.pop_back(),s2.pop_back();
  }
  while(!s1.empty()){
    ans.push_back('9');
    s1.pop_back(),s2.pop_back();
  }
  int t1=1,t2=1;
  for(auto &it:)
  cout<<ans<<'\n';
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