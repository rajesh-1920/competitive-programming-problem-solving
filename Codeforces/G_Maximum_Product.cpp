// Author:  Rajesh Biswas
// CF    :  rajesh_1920
// Date  :  12.09.2026

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
int mul(int n){
  int a=1;
  while(n){
    a*=(n%10);
    n/=10;
  }
  return a;
}
void solve(void)
{
  int a,b;
  cin>>a>>b;
  int x=1,cnt=0;
  while(x<b)
    x*=10,cnt++;
  x/=10,cnt--;
  priority_queue<pair<int,int>>pq;
  pq.push({mul(b),b});

  while(x){
    int tb=b-x,t=1;
    for(int i=1;i<=cnt;i++)
      tb/=10;
    for(int i=1;i<=cnt;i++)
      tb=tb*10+9;
    if(tb>=a)
      pq.push({mul(tb),tb});
    x/=10,cnt--;
  }
  cout<<(pq.top().sc)<<'\n';
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