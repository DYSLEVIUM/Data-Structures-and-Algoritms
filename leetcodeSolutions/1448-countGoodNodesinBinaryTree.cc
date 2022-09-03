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
    int goodNodes(TreeNode* root) {
      int cnt = 0;
      auto dfs = [&cnt](const auto &dfs, TreeNode * const node, int curr_max){
        if(!node) {
          return ;
        }
        
        if(node->val >= curr_max) {
          ++cnt;
          curr_max = node->val;
        }
        
        
        dfs(dfs, node->left, curr_max);
        dfs(dfs, node->right, curr_max);
      };
      dfs(dfs, root, root->val);
      
      return cnt;
    }
};
