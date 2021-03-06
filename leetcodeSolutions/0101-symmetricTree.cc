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
    
    TreeNode* invertTree(TreeNode* root){
        if(root==nullptr) return nullptr;
        
        swap(root->left, root->right);
        
        invertTree(root->left);
        invertTree(root->right);
        
        return root;
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p!=nullptr && q!=nullptr)
            return isSameTree(p->left,q->left) && isSameTree(p->right, q->right) && p->val == q->val;
        else if(p==nullptr && q==nullptr)
            return true;
        else 
            return false;
    }
    
    bool isSymmetric(TreeNode* root) {
        return isSameTree(root->left, invertTree(root->right));
    }
};
