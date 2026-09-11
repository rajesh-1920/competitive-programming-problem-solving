#include <bits/stdc++.h>
using namespace std;
//-----------------------------------------------------------------------------------------

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

class Solution {
// cout << fixed << showpoint << setprecision(10);
#define dbg(x) cout << #x << " = " << x << ' '

public:
    void dfs(TreeNode* root, int n, vector<int>& val, vector<int>& sum,
             vector<int>& cnt,vector<int>& temp,vector<int>& left,vector<int>& right) 
             {
        if (root == NULL)
            return;
        cnt[n] = 1;
        sum[n] = root->val;

        left[n]=temp.back();
        temp.pop_back();
        right[n]=temp.back();
        temp.pop_back();

        dfs(root->left,left[n], val, sum, cnt,temp,left,right);
        dfs(root->right,right[n], val, sum, cnt,temp,left,right);

        sum[n] += sum[left[n]] + sum[right[n]];
        cnt[n] += cnt[left[n]] + cnt[right[n]];
        val[n] = root->val;
    }
    int averageOfSubtree(TreeNode* root) {
        vector<int> val(100010, -1), sum(100010, 0), cnt(100010, 0),temp(100010),
        left(100010, 0),right(100010, 0);
        for(int i=0;i<temp.size();i++)
        temp[i]=i;

        int n=temp.back();
        temp.pop_back();
        dfs(root, n, val, sum, cnt,temp,left,right);

        int ans = 0;
        for (int i = 0; i < sum.size(); i++)
            if (cnt[i])
                ans += ((sum[i] / cnt[i]) == val[i]);
        return ans;
    }
};
//-----------------------------------------------------------------------------------------
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    {
        Solution aa;
        TreeNode* root =
            new TreeNode(4, new TreeNode(8, new TreeNode(0), new TreeNode(1)),
                         new TreeNode(5, NULL, new TreeNode(6)));
        cout << (aa.averageOfSubtree(root)) << '\n';
    }
    return 0;
}
