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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_set<TreeNode *> ans;
        
        unordered_map<string, int> mp;
        auto post_order = [&](const auto & post_order, TreeNode * const node) -> string {
            if(!node) return "N";

            string le = post_order(post_order, node->left);
            string ri = post_order(post_order, node->right);

            string curr = "L" + le + to_string(node->val) + ri + "R";
            if(1 == mp[curr]) ans.insert(node);

            ++mp[curr];

            return curr;
        };

        post_order(post_order, root);

        return vector<TreeNode *> (ans.begin(), ans.end());
    }
};
