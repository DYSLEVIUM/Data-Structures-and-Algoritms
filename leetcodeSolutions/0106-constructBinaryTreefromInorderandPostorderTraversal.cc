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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/solutions/758462/c-detail-explain-diagram/
        int in_sz = inorder.size(), po_sz = postorder.size();
        auto build = [&](const auto & build, const int & in_s, const int & in_e, const int & po_s, const int & po_e) -> TreeNode * {
            if(in_s > in_e || po_e > po_e) {
                return nullptr;
            }

            TreeNode * node = new TreeNode(postorder[po_e]);

            int par = in_s;  
            while(node->val != inorder[par]) {
                par++;
            }

            node->left = build(build, in_s, par - 1, po_s, po_s + par - in_s - 1);
            node->right = build(build, par + 1, in_e, po_s + par - in_s, po_e - 1);
            
            return node;
        };

        return build(build, 0, in_sz - 1, 0, po_sz - 1);
    }
};
