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
    int findHeight(TreeNode* root){
        if(root==nullptr) return 0;
        
        int lHeight = findHeight(root->left);
        int rHeight = findHeight(root->right);
        
        return max(lHeight, rHeight)+1;
    }
    
    bool isBalanced(TreeNode* root) {
        if(root==nullptr) return true;
        
        int lHeight = findHeight(root->left);
        int rHeight = findHeight(root->right);
        
        return isBalanced(root->left) && isBalanced(root->right) && abs(lHeight-rHeight)<=1;
    }
};
