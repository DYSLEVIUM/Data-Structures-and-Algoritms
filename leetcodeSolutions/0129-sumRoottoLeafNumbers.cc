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
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        auto dfs = [&](const auto &dfs, const TreeNode *node, int &curr_num){
            if(!node) return;
            
            curr_num = curr_num * 10 + node->val;
            
            if(!node->left && !node->right) {
                sum += curr_num;
                curr_num /= 10;
                
                return;
            }
            
            dfs(dfs, node->left, curr_num);
            dfs(dfs, node->right, curr_num);
            
            curr_num /= 10;
        };
        
        int curr_num = 0;
        dfs(dfs, root, curr_num);
        
        return sum;
    }
};
