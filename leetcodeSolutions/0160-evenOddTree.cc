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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode *> qu;
        qu.push(root);

        int level = 0;
        while(!qu.empty()) {
            int prev = INT_MIN;
            bool should_be_even = false;

            if(level & 1) {
                should_be_even = true;
                prev = INT_MAX;
            }

            int sz = qu.size();
            while(sz--) {
                TreeNode * fr = qu.front();
                qu.pop();

                if(should_be_even) {
                    if(fr->val % 2 != 0 || fr->val >= prev) return false;
                } else {
                    if(fr->val % 2 == 0 || fr->val <= prev) return false;
                }
                prev = fr->val;

                if(fr->left) qu.push(fr->left);
                if(fr->right) qu.push(fr->right);
            }
            ++level;
        }

        return true;
    }
};
