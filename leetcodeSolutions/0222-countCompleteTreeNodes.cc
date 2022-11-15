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
    int countNodes(TreeNode* root) {
        if(!root) return 0;

        int le_cnt = 0, ri_cnt = 0;
        TreeNode * le = root, * ri = root;

        while(le) le = le->left, ++le_cnt;
        while(ri) ri = ri->right, ++ri_cnt;

        if(le_cnt == ri_cnt) return (1 << le_cnt) - 1;
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
