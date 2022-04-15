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
    int minDiffInBST(TreeNode* root) {
      int minn = INT_MAX;
      auto inorder = [&minn](const auto &inorder, TreeNode *const node, int &prev_val) -> void {
        if(node->left) inorder(inorder, node->left, prev_val);
        
        if(prev_val != -1) minn = min(minn, abs(node->val - prev_val));
        
        //  this cannot be const, as after we traverse to the child nodes, we update this value for the parent to use
        prev_val = node->val;
        
        if(node->right) inorder(inorder, node->right, prev_val);
      };
      int prev_val = -1;
      inorder(inorder, root, prev_val);
      
      return minn;      
    }
};
