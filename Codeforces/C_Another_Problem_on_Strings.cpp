// Author:  Rajesh Biswas
// CF    :  rajesh_1920
// Date  :  13.09.2026

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
  int k,cnt=0,ans=0;
  string s;
  cin>>k>>s;
  vector<int>left(s.size(),0),right(s.size(),0);
  for(int i=0;i<s.size();i++){
    left[i]=cnt;
    if(s[i]=='1')
      {
        ans+=(cnt*(cnt+1)/2);
        cnt=0;
      }
    else
      cnt++;
  }
  ans+=(cnt*(cnt+1)/2);
  if(k==0){
    cout<<ans<<'\n';
    return;
  }
  cnt=0;
  for(int i=s.size()-1;i>=0;i--){
    right[i]=cnt;
    if(s[i]=='1')
      cnt=0;
    else
      cnt++;
  }

  int l=0,r=0;
  ans=0,cnt=1;
  while(l<s.size()&&s[l]=='0'){
      l++;
    }
    r=l+1;

  while(l<s.size()){
     while(l<s.size()&&s[l]=='0'){
      l++;
    }
    while(r<s.size()&&cnt<k){
      cnt+=(s[r]=='1');
      r++;
    }
    if(cnt==k &&l<s.size()&&r<=s.size())
        {
          
          ans+=(left[l]+1)*(right[r-1]+1);
        }
    l++,cnt--;
  }
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