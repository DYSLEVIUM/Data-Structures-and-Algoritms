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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
      if(!root) {
        return false;
      }
      
      auto is_same = [](const auto &is_same, TreeNode * const &node, TreeNode * const &sub_node){
        if(!node && !sub_node) {
          return true;
        }
      
        if(!node || !sub_node || node->val != sub_node->val) {
          return false;
        }
        
        return is_same(is_same, node->left, sub_node->left) && is_same(is_same, node->right, sub_node->right);
      };
      
      return is_same(is_same, root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
