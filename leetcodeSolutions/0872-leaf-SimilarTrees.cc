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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        auto get_leaf_seq = [](const auto &get_leaf_seq, TreeNode * const node, vector<int> &seq){
            if(!node) {
                return ;
            }

            if(!node->left && !node->right) {
                seq.push_back(node->val);
                return ;
            }

            get_leaf_seq(get_leaf_seq, node->left, seq);
            get_leaf_seq(get_leaf_seq, node->right, seq);
        };

        vector<int> sq1, sq2;
        get_leaf_seq(get_leaf_seq, root1, sq1), get_leaf_seq(get_leaf_seq, root2, sq2);

        if(sq1.size() != sq2.size()) {
            return false;
        }

        for(int i = 0; i < sq1.size(); ++i) {
            if(sq1[i] != sq2[i]) {
                return false;
            }
        }

        return true;
    }
};
