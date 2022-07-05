/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
      int ans = INT_MIN;
      auto dfs = [&](const auto &dfs, TreeNode * const node){
        if(!node) {
          return 0;
        }
        
        int left = max(dfs(dfs, node->left), 0);
        int right = max(dfs(dfs, node->right), 0);
        
        ans = max(ans, node->val + left + right);
        
        return node->val + max(left, right);
      };
      dfs(dfs, root);
      
      return ans;
    }
};
