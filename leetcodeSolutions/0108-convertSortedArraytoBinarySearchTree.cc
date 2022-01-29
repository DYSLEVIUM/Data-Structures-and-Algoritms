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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
      auto makeBST = [nums](const auto& makeBST, const int& start, const int& end)->TreeNode*{
        if(end < start) return nullptr;
        
        int mid = start + (end - start) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        
        node->left = makeBST(makeBST, start, mid-1);
        node->right = makeBST(makeBST, mid+1, end);

        return node;
      };
      
      int n = nums.size();
      
      return makeBST(makeBST, 0, n-1);  
    }
};
