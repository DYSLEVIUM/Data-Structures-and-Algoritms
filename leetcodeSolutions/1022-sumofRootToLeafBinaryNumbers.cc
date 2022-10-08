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
    int sumRootToLeaf(TreeNode* root) {
        auto dfs = [](const auto &dfs, TreeNode * const node, const int &val){
            if(!node) {
                return 0;
            }

            int new_val = (val << 1) | node->val;
            
            if(!node->left && !node->right) {
                return new_val;
            }

            return dfs(dfs, node->left, new_val) + dfs(dfs, node->right, new_val);
        };

        return dfs(dfs, root, 0);
    }
};
