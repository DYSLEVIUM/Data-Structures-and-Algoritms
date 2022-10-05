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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(!root) {
            return new TreeNode(val);
        }

        if(depth == 1) {
            return new TreeNode(val, root, nullptr);
        }

        queue<TreeNode *> qu;
        qu.push(root);
        --depth;

        while(--depth) {
            int sz = qu.size();
            while(sz--) {
                auto node = qu.front();
                qu.pop();

                if(node->left) {
                    qu.push(node->left);
                }

                if(node->right) {
                    qu.push(node->right);
                }
            }
        }

        while(!qu.empty()) {
            auto node = qu.front();
            qu.pop();

            node->left = new TreeNode(val, node->left, nullptr);
            node->right = new TreeNode(val, nullptr, node->right);
        }

        return root;
    }
};
