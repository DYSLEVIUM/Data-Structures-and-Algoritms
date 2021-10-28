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
    int sumEvenGrandparent(TreeNode* root) {
        if(root == nullptr) return 0;
        
        auto getSum = [](TreeNode* node, bool isParentEven, bool isGrandparentEven, const auto& getSum) -> int{
            int le = 0;
            if(node->left != nullptr) le = getSum(node->left, node->val % 2 == 0, isParentEven, getSum);
            
            int ri = 0;
            if(node->right != nullptr) ri = getSum(node->right, node->val % 2 == 0, isParentEven, getSum);
            
            if(isGrandparentEven) return node->val + le + ri;
            
            return le + ri;
        };
        
        return getSum(root, false, false, getSum);
    }
};
