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
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr) return 0;
        
        int dia = 0;
        
        auto findHeight = [&dia](TreeNode* node, auto&& findHeight){
            if(node==nullptr) return 0;
            
            int l = findHeight(node->left, findHeight);
            int r = findHeight(node->right, findHeight);
            
            dia = max(dia, l+r+1);
            
            return 1+max(l,r);
        };
        
        findHeight(root,findHeight);
        
        return dia-1;
    }
};
