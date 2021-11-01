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
    TreeNode* balanceBST(TreeNode* root) {
        if(root==nullptr) return nullptr;
        
        vector<int> inorder;
        
        auto getInorder = [&inorder](TreeNode* node, const auto& getInorder){
            if(node==nullptr) return;
            
            getInorder(node->left, getInorder);
            inorder.emplace_back(node->val);
            getInorder(node->right, getInorder);
        };
        
        getInorder(root, getInorder);
        
        auto buildBST = [&inorder](int lo, int hi, const auto& buildBST)->TreeNode*{
            if(lo > hi) return nullptr;
            
            int mid = lo + (hi-lo)/2;
            
            TreeNode* root = new TreeNode(inorder[mid]);
            
            root->left = buildBST(lo, mid-1, buildBST);
            root->right = buildBST(mid+1, hi, buildBST);

            return root;
        };
        
        return buildBST(0, inorder.size()-1, buildBST);
    }
};
