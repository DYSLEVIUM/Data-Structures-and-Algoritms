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
    TreeNode* bstToGst(TreeNode* root) {
            int sum = 0;
      auto convert_to_greater_tree = [&sum](const auto &convert_to_greater_tree, TreeNode  *node) -> void {
        if(!node) return;
        convert_to_greater_tree(convert_to_greater_tree, node->right);
        node->val += sum;
        sum = node->val;
        convert_to_greater_tree(convert_to_greater_tree, node->left);
      };
      convert_to_greater_tree(convert_to_greater_tree, root);
      
      return root;
    }
};
