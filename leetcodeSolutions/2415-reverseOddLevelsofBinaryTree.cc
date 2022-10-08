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
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(!root) {
            return nullptr;
        }

        int cnt = 0;
        queue<TreeNode *> qu;
        qu.push(root);
        while(!qu.empty()) {
            int sz = qu.size();
            vector<TreeNode *> level_nodes;
            while(sz--) {
                auto node = qu.front();
                qu.pop();

                level_nodes.push_back(node);

                if(node->left) {
                    qu.push(node->left);
                }

                if(node->right) {
                    qu.push(node->right);
                }
            }

            if(cnt & 1) {
                int n = level_nodes.size();
                for(int i = 0; i < n / 2; ++i) {
                    swap(level_nodes[i]->val, level_nodes[n - 1 - i]->val);
                }
            }
            ++cnt;
        }

        return root;
    }
};
