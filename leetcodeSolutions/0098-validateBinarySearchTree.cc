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
    bool isValidBST(TreeNode* root) {
        auto is_bst = [&](const auto &is_bst, TreeNode * const &node, TreeNode * const &mn, TreeNode * const &mx) {
            if(!node) {
                return true;
            }

            if((mn && mn->val >= node->val) || (mx && mx->val <= node->val)) {
                return false;
            }
            
            return is_bst(is_bst, node->left, mn, node) && is_bst(is_bst, node->right, node, mx);
        };
        
        return is_bst(is_bst, root, nullptr, nullptr);
    }
};
