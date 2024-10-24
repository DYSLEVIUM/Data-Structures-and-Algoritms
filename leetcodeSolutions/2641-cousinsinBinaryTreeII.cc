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

#pragma GCC optimize("O3", "unroll-loops")

auto _ = [](){
    return cin.tie(nullptr)->sync_with_stdio(false);
}();

class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<pair<TreeNode *, TreeNode *>> qu;
        qu.push({root, nullptr});

        int sum = 0;
        while(!qu.empty()) {
            int sz = qu.size();

            vector<TreeNode *> nodes;
            nodes.reserve(sz);

            int level_sum = 0;

            unordered_map<TreeNode *, TreeNode *> parent;
            unordered_map<TreeNode *, int> parent_sum;

            while(sz--) {
                auto [node, par] = qu.front();
                qu.pop();

                parent[node] = par;
                level_sum += node->val;
                parent_sum[par] += node->val;

                nodes.emplace_back(node);

                if(node->left) {
                    qu.push({node->left, node});
                }

                if(node->right) {
                    qu.push({node->right, node});
                }
            }

            for(auto & node: nodes) {
                node->val = level_sum - parent_sum[parent[node]];
            }
        }

        return root;
    }
};
