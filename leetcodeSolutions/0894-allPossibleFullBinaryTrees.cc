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
    TreeNode *deep_copy(TreeNode *node) {
      if(!node) {
        return nullptr;
      }
      
      TreeNode *new_node = new TreeNode();
      new_node->left = deep_copy(node->left);
      new_node->right = deep_copy(node->right);
      
      return new_node;
    }
  
    vector<TreeNode*> allPossibleFBT(int n) {
      vector<TreeNode *> res;
      if(n == 1) {
        res.emplace_back(new TreeNode());
      } else if(n & 1) {
        //  starting from 1, as we need one root
        for(int i = 1; i < n; ++i) {
          //  i nodes to left, n - 1 - i nodes to the right
          auto left = allPossibleFBT(i), right = allPossibleFBT(n - 1 - i);
          
          int left_size = left.size(), right_size = right.size();
          
          for(int l_idx = 0; l_idx < left_size; ++l_idx) {
            for(int r_idx = 0; r_idx < right_size; ++r_idx) {
              TreeNode *new_node = new TreeNode();
              new_node->left = deep_copy(left[l_idx]);
              new_node->right = deep_copy(right[r_idx]);

              res.push_back(new_node);
            }
          }
        }
      }
      
      return res;
    }
};
