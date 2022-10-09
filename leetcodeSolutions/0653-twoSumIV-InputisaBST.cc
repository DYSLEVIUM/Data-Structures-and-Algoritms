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
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> se;
        auto dfs = [&](const auto &dfs, TreeNode * const node){
            if(!node) {
                return false;
            }

            if(se.count(k - node->val)) {
                return true;
            }

            se.insert(node->val);

            return dfs(dfs, node->left) || dfs(dfs, node->right);
        };
        return dfs(dfs, root);
    }
};
