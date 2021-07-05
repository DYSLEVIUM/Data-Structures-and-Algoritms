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
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        
        int lDepth;
        int rDepth;
        
        if(root->left==nullptr)
            lDepth = INT_MAX;
        else
            lDepth = minDepth(root->left);
        
        if(root->right==nullptr)
            rDepth = INT_MAX;
        else
            rDepth = minDepth(root->right);
        
        if(root->left==nullptr && root->right==nullptr) return 1;
        
        return min(lDepth,rDepth)+1;
    }
};
