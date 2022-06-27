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
    int averageOfSubtree(TreeNode* root) {
      int ans = 0;
      auto post_order = [&](const auto &post_order, TreeNode *node)->pair<int, int>{
        if(!node) {
          return { 0, 0 };
        }
        
        auto le = post_order(post_order, node->left);
        auto ri = post_order(post_order, node->right);
        
        int total_val = node->val + le.first + ri.first;
        int total_nodes = 1 + le.second + ri.second;
        
        ans += (total_val / total_nodes) == node->val;
        
        return { total_val, total_nodes };
      };
      post_order(post_order, root);
      return ans;
    }
};
