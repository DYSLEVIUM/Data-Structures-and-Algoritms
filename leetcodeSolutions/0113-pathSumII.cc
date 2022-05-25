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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        auto dfs = [&](const auto &dfs, const TreeNode *node, int &curr_sum, vector<int> &curr_vals){
            if(!node) return;
            
            curr_sum += node->val;
            curr_vals.push_back(node->val);

            if(!node->left && !node->right) {
                if(curr_sum == targetSum) ans.push_back(curr_vals);
            } else {
                dfs(dfs, node->left, curr_sum, curr_vals);
                dfs(dfs, node->right, curr_sum, curr_vals);
            }
                        
            curr_vals.pop_back();
            curr_sum -= node->val;
        };
        
        int curr_sum = 0;
        vector<int> curr_ans;
        dfs(dfs, root, curr_sum, curr_ans);
        
        return ans;
    }
};
