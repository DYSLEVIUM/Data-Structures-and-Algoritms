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
    int maxAncestorDiff(TreeNode* root) {
        int diff = INT_MIN;
        auto recur = [&](const auto &recur, TreeNode * const node) -> pair<int, int> {
            if(!node) {
                return {INT_MAX, INT_MIN};
            }

            auto le = recur(recur, node->left);
            auto ri = recur(recur, node->right);

            int minn = min(le.first, ri.first);
            int maxx = max(le.second, ri.second);

            if(minn != INT_MAX && maxx != INT_MIN) {
                diff = max({diff, abs(node->val - minn), abs(node->val - maxx)});          
            }
            
            return {min(node->val, minn), max(node->val, maxx)};
        };
        recur(recur, root);

        return diff;
    }
};
