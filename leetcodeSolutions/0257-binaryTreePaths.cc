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
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root==nullptr) return vector<string>(0);
        
        vector<string> ans;

        auto dfs = [&ans](TreeNode* root, string pt, auto&& dfs){
            pt += to_string(root->val);
            
            if(root->left==nullptr && root->right==nullptr){
                ans.push_back(pt);
                return;
            }
            
            pt += "->";
            
            if(root->left!=nullptr) dfs(root->left, pt, dfs);
            if(root->right!=nullptr) dfs(root->right, pt, dfs);
        };
        
        dfs(root, "", dfs);
        
        return ans;
    }
};
