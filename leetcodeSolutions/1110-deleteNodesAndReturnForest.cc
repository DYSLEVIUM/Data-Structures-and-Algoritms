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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode *> ans;
        unordered_set<int> del(to_delete.begin(), to_delete.end());
        auto dfs = [&](const auto & dfs, TreeNode * &node, TreeNode * const &parent){
            if(!node) return ;

            TreeNode * le = node->left, * ri = node->right;

            if(del.count(node->val)) {
                if(parent) {
                    if(node == parent->left) parent->left = nullptr;
                    else parent->right = nullptr;
                }
                node = nullptr;
            } else {
                if(parent == nullptr) ans.push_back(node);
            }

            dfs(dfs, le, node);
            dfs(dfs, ri, node);
        };
        dfs(dfs, root, nullptr);

        return ans;
    }
};
