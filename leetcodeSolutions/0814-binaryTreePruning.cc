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
    TreeNode* pruneTree(TreeNode* root) {
      auto recur = [&](const auto &recur, TreeNode * &node){
        if(!node) {
          return false;
        }
        
        bool le = recur(recur, node->left);
        bool ri = recur(recur, node->right);
              
        if(node->val != 1 && !le && !ri) {
          node = nullptr;
          return false;
        }
        
        if(!le) {
          node->left = nullptr;
        }
          
        if(!ri) {
          node->right = nullptr;
        }
        
        return true;
      };
      recur(recur, root);
      
      return root;
    }
};
