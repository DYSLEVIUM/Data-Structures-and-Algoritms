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
    int findTilt(TreeNode* root) {
        
        int sum = 0;
        
        auto findTiltRecur = [&](const auto& findTiltRecur, const TreeNode* node){
            if(node==nullptr) return 0;
        
            int le = findTiltRecur(findTiltRecur, node->left);
            int ri = findTiltRecur(findTiltRecur, node->right);
            
            sum+=abs(le-ri);
            
            return le+ri+node->val;
        };
        
        findTiltRecur(findTiltRecur, root);
        
        return sum;
    }
};
