#include <bits/stdc++.h>
using namespace std;
//-----------------------------------------------------------------------------------------
class Solution
{
// cout << fixed << showpoint << setprecision(10);
#define dbg(x) cout << #x << " = " << x << '\n'

public:
int totalNumbers(vector<int>& digits) {
        set<int> st;
        sort(digits.begin(),digits.end());
        do{
          int x=digits[0]+10*digits[1]+100*digits[2];
          if(x>99&&x<1000&&x%2==0)
          st.insert(x);

        }while(next_permutation(digits.begin(),digits.end()));
        return (int)st.size();
    }
};
//-----------------------------------------------------------------------------------------
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    {
        Solution aa;
        vector<int>d={1,2,3,4};
        cout<<aa.totalNumbers(d)<<'\n';
    }
    return 0;
}
