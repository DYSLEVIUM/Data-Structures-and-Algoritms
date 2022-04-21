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
    int kthSmallest(TreeNode* root, int k) {        
      int cnt = 0, ans;
      auto inorder = [&](const auto &inorder, TreeNode *node) -> void {
        if(!node) return;

        inorder(inorder, node->left);
        ++cnt;
        if(cnt == k) {
          ans = node->val;
          return;
        }
        inorder(inorder, node->right);
      };
      inorder(inorder, root);

      return ans;
    }
};
