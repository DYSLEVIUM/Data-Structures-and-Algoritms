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
    bool isUnivalTree(TreeNode* root) {
        unordered_set<int> se;
        auto dfs = [&](const auto &dfs, const TreeNode * node){
            if(!node) return ;
            se.insert(node->val);
            dfs(dfs, node->left), dfs(dfs, node->right);
        };
        dfs(dfs, root);

        return se.size() == 1;
    }
};
