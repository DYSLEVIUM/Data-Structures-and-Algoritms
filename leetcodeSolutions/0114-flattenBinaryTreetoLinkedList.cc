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
    void flatten(TreeNode* root) {
      if(!root) return;
      if(!root->left && !root->right) return;
      
      flatten(root->left);
      flatten(root->right);
      
      if(root->left) {
        TreeNode* curr_root = root;
        TreeNode* curr_right = root->right;
        
        curr_root->right = curr_root->left;
        
        while(root->right) root = root->right;
        root->right = curr_right;
        
        curr_root->left = nullptr;
      }
    }
};
