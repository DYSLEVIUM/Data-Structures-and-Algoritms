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
    int distributeCoins(TreeNode* root) {
      int ans = 0;
      auto dfs = [&](const auto &dfs, TreeNode * const node){
        if(!node) return 0;
        
        //  how much extra does left and right have (can be negative extra)
        int le = dfs(dfs, node->left);
        int ri = dfs(dfs, node->right);
        ans += abs(le) + abs(ri);
        
        return node->val + le + ri - 1;
      };
      dfs(dfs, root);
    
      return ans;
    }
};
