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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        auto makeTree = [&nums](int lPtr, int rPtr, const auto& makeTree){
            if(lPtr>rPtr) return (TreeNode*)nullptr;
            
            //  finding the maximum (can be optimized with segment tree(range maximum query))
            int maxi = INT_MIN;
            int idx = -1;
            for(int i=lPtr;i<=rPtr;++i){
                if(maxi<nums[i]){
                    idx = i;
                    maxi = nums[i];
                }
            }
            
            TreeNode* node = new TreeNode(maxi);
            
            node->left = makeTree(lPtr, idx-1,makeTree);
            node->right = makeTree(idx+1, rPtr,makeTree);
            
            return node;
        };

        
        return makeTree(0, nums.size()-1, makeTree);
    }
};
