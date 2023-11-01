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
    vector<int> findMode(TreeNode* root) {
        int maxx = 0;
        vector<int> ans;
        auto inorder = [&](const auto & inorder, const TreeNode * const node, int & prev, int & cnt){
            if(!node) {
                return ;
            }

            inorder(inorder, node->left, prev, cnt);

            if(node->val == prev) {
                ++cnt;
            } else {
                cnt = 1;
                prev = node->val;
            }

            if(cnt > maxx) {
                ans = {};
                maxx = cnt;
            }

            if(cnt == maxx) {
                ans.push_back(prev);
            }

            inorder(inorder, node->right, prev, cnt);
        };

        int prev = -1, cnt = 0;
        inorder(inorder, root, prev, cnt);

        return ans;
    }
};
