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
    int rob(TreeNode* root) {
      auto dfs = [](const auto &dfs, TreeNode * const &node) -> pair<int, int> {
        if(!node) {
          return {0, 0};
        }
        
        auto le = dfs(dfs, node->left);
        auto ri = dfs(dfs, node->right);
        
        // if curr is not robbed, we get the max of its child's robbed and not robbed
        int curr_not_robbed = max(le.first, le.second) + max(ri.first, ri.second);
        // if curr is robbed, we get the child's not robbed
        int curr_robbed = node->val + le.second + ri.second;
        
        return {curr_robbed, curr_not_robbed};
      };
      
      auto ans = dfs(dfs, root);
      return max(ans.first, ans.second);
    }
};
