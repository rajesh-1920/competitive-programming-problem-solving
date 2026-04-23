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
const int N = 1e5 + 10;
//-----------------------------------------------------------------------------------------
void solve(void)
{
   
long long n;
cin>>n;
if(n%2==0)
{
    cout<<(n/2)<<endl;
    for(long long i=0;i<(n/2);i++)
    {
       cout<<2<<" ";
    }
    cout<<endl;
}
else{
    cout<<(n/2)<<endl;
    for(long long i=0;i<(n/2)-1;i++)
    {
       cout<<2<<" ";
    }
    cout<<3<<endl;
}
}
//-----------------------------------------------------------------------------------------
signed main()
{
    // cout << fixed << showpoint << setprecision(10);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1, T;
    //cin >> test;
    for (T = 1; T <= test; T++)
    {
        // cout << "Case " << T << ": ";
        solve();
    }
    return 0;
}